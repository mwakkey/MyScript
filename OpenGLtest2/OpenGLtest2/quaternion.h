#pragma once

namespace MathFunc {
	struct mQuat
	{
		float v[3];
		float w;
	};

	class Quarternion{
	private:
		//対象座標ベクトルであるクォータニオン(の係数)を定義
		static mQuat& create(float x, float y, float z, float w);
		//任意軸回りの任意回転を表すクォータニオン
		static mQuat& quat(float rotAxis[], float rotAngle);
		static mQuat& multiply(const mQuat& a, const mQuat& b);
	public:
		//座標ベクトルを回転軸に対して回転させる
		static mQuat& rotate(float rotVec[], float rotAxis[], float rotAngle);
	};
}