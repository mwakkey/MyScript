#pragma once

namespace MathFunc {
	struct mQuat
	{
		float v[3];
		float w;
	};

	class Quarternion{
	private:
		//���W�x�N�g���ŃN�H�[�^�j�I��(�̌W��)���`
		static void create(float x, float y, float z, float w,mQuat& q);
		//�C�ӎ����̔C�Ӊ�]���N�H�[�^�j�I���ŕ\��
		static void quat(float rotAxis[], float rotAngle, mQuat& q);
		static void multiply(const mQuat& a, const mQuat& b, mQuat& q);
	public:
		//���W�x�N�g������]���ɑ΂��ĉ�]������
		static void rotate(float* rotVec, float rotAxis[], float rotAngle);
	};
}