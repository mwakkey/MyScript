#include "controller.h"
#include <gl/glut.h>
#include <numeric>

//�Q�[�����ł̃L�[�ԍ��ƑΉ�����L�[�̃}�b�v
unsigned int keyFlag;

void Controller::joystick(unsigned int ButtonMask, int x, int y, int z)
{
	unsigned int tmp = 0;
	if (x > 300)          tmp += 1;//right
	if (x < -300)         tmp += 2;//left
	if (y > 300)          tmp += 4;//up
	if (y < -300)         tmp += 8;//down

	keyFlag = (ButtonMask << 4) + tmp;

}



Controller::JoyPad::JoyPad()
{
	myKeyFlag = 0;
}


void Controller::JoyPad::inputJoyStick(int Hz)
{
	glutJoystickFunc(Controller::joystick, Hz);//Hz[ms]�Ɉ��W���C�X�e�B�b�N���͂��󂯕t����
	myKeyFlag = keyFlag;
}


unsigned int Controller::JoyPad::putDown(unsigned int buttonID)
{

	return (myKeyFlag & (2 << buttonID));

}

