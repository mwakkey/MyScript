#include "controller.h"
#include <vector>
#include <gl/glut.h>
#include <numeric>

//ゲーム内でのキー番号と対応するキーのマップ
unsigned int keyFlag;

void Controller::setController()
{
	flagClear();
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

void Controller::flagClear()
{
	keyFlag = 0;
}

unsigned int Controller::inputJoyStick(int Hz)
{
	glutJoystickFunc(joystick, Hz);//Hz[ms]に一回ジョイスティック入力を受け付ける
	return keyFlag;
}


unsigned int Controller::putDown(unsigned int buttonID)
{

	return (keyFlag & (2 << buttonID));

}

