#pragma once

namespace Controller
{
	//�Q�[�����ł̃L�[�ԍ��ƑΉ�����L�[�̃}�b�v
	unsigned int keyFlag;
	void joystick(unsigned int ButtonMask, int x, int y, int z);

	class JoyPad
	{
	private:
		unsigned int myKeyFlag;

	public:
		JoyPad();
		void inputJoyStick(int Hz);
		unsigned int putDown(unsigned int butonID);
	};
};