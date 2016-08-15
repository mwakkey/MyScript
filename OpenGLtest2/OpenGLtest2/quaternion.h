#pragma once

namespace MathFunc {
	struct mQuat
	{
		float v[3];
		float w;
	};

	class Quarternion{
	private:
		//座標ベクトルでクォータニオン(の係数)を定義
		static void create(float x, float y, float z, float w,mQuat& q);
		//任意軸回りの任意回転をクォータニオンで表す
		static void quat(float rotAxis[], float rotAngle, mQuat& q);
		static void multiply(const mQuat& a, const mQuat& b, mQuat& q);
	public:
		//座標ベクトルを回転軸に対して回転させる
		static void rotate(float* rotVec, float rotAxis[], float rotAngle);
	};
}