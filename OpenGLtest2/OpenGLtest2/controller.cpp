#include "controller.h"
#include <gl/glut.h>
#include <numeric>

namespace Controller {
	//�Q�[�����ł̃L�[�ԍ��ƑΉ�����L�[�̃}�b�v
	unsigned int keyFlag;
}

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
	keyDown = 0;
	keyUp = 0;
}


void Controller::JoyPad::inputJoyStick(int Hz)
{
	glutJoystickFunc(Controller::joystick, Hz);//Hz[ms]�Ɉ��W���C�X�e�B�b�N���͂��󂯕t����
	keyDown = keyFlag & (~myKeyFlag);
	keyUp = (keyFlag) & myKeyFlag;
}


unsigned int Controller::JoyPad::getKey(unsigned int buttonID)
{

	return (myKeyFlag & (2 << buttonID));

}

unsigned int Controller::JoyPad::getKeyDown(unsigned int buttonID)
{
	return (keyDown & (2 << buttonID));
}

unsigned int Controller::JoyPad::getKeyUp(unsigned int buttonID)
{
	return (keyUp & (2 << buttonID));
}
