#include "camera.h"
#include "quaternion.h"
#include "calculation.h"
#include <GL/freeglut.h>

Camera::Camera(float p[3], float l[3], float u[3]) {
	for (int i = 0; i < 3; ++i) {
		pos[i] = p[i];
		look[i] = l[i];
		up[i] = u[i];
	}
}

void Camera::rotate(float rotAxis[3], float rotAngle) {
	MathFunc::Quarternion::rotate(look, rotAxis, rotAngle);
	MathFunc::Quarternion::rotate(up, rotAxis, rotAngle);
}

void Camera::translate(float mov[3]) {
	float* tmp = MathFunc::sum(pos, mov);

	pos[0] = tmp[0];
	pos[1] = tmp[1];
	pos[2] = tmp[2];

	delete(tmp);
}

void Camera::lookAt() {
	glLoadIdentity();
	gluLookAt(pos[0], pos[1], pos[2], look[0], look[1], look[2], up[0], up[1], up[2]);
}