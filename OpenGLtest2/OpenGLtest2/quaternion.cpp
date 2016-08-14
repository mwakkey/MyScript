#include "quaternion.h"
#include "crossProd.h"
#include "innerProd.h"
#include "calculation.h"
#include <cmath>
#include <numeric>

using namespace MathFunc;
mQuat& Quarternion::create(float x, float y, float z, float w) {
	mQuat q;
	q.v[0] = x;
	q.v[1] = y;
	q.v[2] = z;
	q.w = w;

	return q;
	}

	mQuat& Quarternion::quat(float rotAxis[], float rotAngle) {
		mQuat q;
		q.v[0] = rotAxis[0] * std::sin(rotAngle / 2);
		q.v[1] = rotAxis[1] * std::sin(rotAngle / 2);
		q.v[2] = rotAxis[2] * std::sin(rotAngle / 2);
		q.w = std::cos(rotAngle / 2);

		return q;
	}

	mQuat& Quarternion::multiply(const mQuat& a, const mQuat& b) {
		mQuat c;
		float* temp = MathFunc::sum(CrossProd::cross3D<float>(a.v, b.v), MathFunc::multiply<float>(b.w, a.v), MathFunc::multiply<float>(a.w, b.v));

		for (int i = 0; i < 3; ++i) {
			c.v[i] = temp[i];
		}
		delete(temp);

		c.w = a.w*b.w - InnerProd::dotProd(a.v, b.v);

		return c;
	}

	mQuat& Quarternion::rotate(float rotVec[], float rotAxis[], float rotAngle) {
		mQuat P = Quarternion::create(rotVec[0], rotVec[1], rotVec[2], 0);
		mQuat R = quat(rotAxis, rotAngle);
		mQuat Q = Quarternion::create(-R.v[0], -R.v[1], -R.v[2], R.w);
		mQuat S0 = Quarternion::multiply(P, Q);
		mQuat S = Quarternion::multiply(R, S0);
		
		return S;
	}

