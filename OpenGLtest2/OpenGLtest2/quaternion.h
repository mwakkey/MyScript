#pragma once

namespace MathFunc {
	struct mQuat
	{
		float v[3];
		float w;
	};

	class Quarternion{
	private:
		//�Ώۍ��W�x�N�g���ł���N�H�[�^�j�I��(�̌W��)���`
		static mQuat& create(float x, float y, float z, float w);
		//�C�ӎ����̔C�Ӊ�]��\���N�H�[�^�j�I��
		static mQuat& quat(float rotAxis[], float rotAngle);
		static mQuat& multiply(const mQuat& a, const mQuat& b);
	public:
		//���W�x�N�g������]���ɑ΂��ĉ�]������
		static mQuat& rotate(float rotVec[], float rotAxis[], float rotAngle);
	};
}