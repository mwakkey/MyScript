#include "quaternion.h"
#include "crossProd.h"
#include "innerProd.h"
#include "calculation.h"
#include <cmath>
#include <numeric>

using namespace MathFunc;
void Quarternion::create(float x, float y, float z, float w, mQuat& q) {
	mQuat q;
	q.v[0] = x;
	q.v[1] = y;
	q.v[2] = z;
	q.w = w;
}

void Quarternion::quat(float rotAxis[], float rotAngle, mQuat& q) {
	mQuat q;
	q.v[0] = rotAxis[0] * std::sin(rotAngle / 2);
	q.v[1] = rotAxis[1] * std::sin(rotAngle / 2);
	q.v[2] = rotAxis[2] * std::sin(rotAngle / 2);
	q.w = std::cos(rotAngle / 2);
}

void Quarternion::multiply(const mQuat& a, const mQuat& b, mQuat& q) {
	mQuat c;
	float* temp = MathFunc::sum(CrossProd::cross3D<float>(a.v, b.v), MathFunc::multiply<float>(b.w, a.v), MathFunc::multiply<float>(a.w, b.v));

	for (int i = 0; i < 3; ++i) {
		c.v[i] = temp[i];
	}
	delete(temp);

	c.w = a.w*b.w - InnerProd::dotProd(a.v, b.v);

}

float* Quarternion::rotate(float rotVec[], float rotAxis[], float rotAngle) {
	mQuat P, R, Q, S0, S;
	create(rotVec[0], rotVec[1], rotVec[2], 0, P);
	quat(rotAxis, rotAngle, R);
	create(-R.v[0], -R.v[1], -R.v[2], R.w, Q);
	multiply(P, Q, S0);
	multiply(R, S0, S);

	return S.v;
}

