#pragma once



class Camera {
private:
	float pos[3];
	float look[3];
	float up[3];

public:
	Camera(float p[3], float l[3], float u[3]);
	void rotate(float rotAxis[3], float rotAngle);
	void translate(float mov[3]);

	void lookAt();
};