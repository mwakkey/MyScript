#include "controller.h"
#include <vector>
#include <gl/glut.h>


//ゲーム内でのキー番号と対応するキーのマップ
std::vector<bool> keyFlag;

void Controller::setController(int buttons)
{
	keyFlag.resize(buttons);
}

void Controller::joystick(unsigned int ButtonMask, int x, int y, int z)
{
	flagClear();

	if (x > 300)          keyFlag[0] = true;//right
	if (x < -300)         keyFlag[1] = true;//left
	if (y > 300)          keyFlag[2] = true;//up
	if (y < -300)         keyFlag[3] = true;//down

	if (ButtonMask & 1)   keyFlag[4] = true;//A
	if (ButtonMask & 2)   keyFlag[5] = true;//B
	if (ButtonMask & 4)   keyFlag[6] = true;//C
	if (ButtonMask & 8)   keyFlag[7] = true;//X
	if (ButtonMask & 16)  keyFlag[8] = true;//Y
	if (ButtonMask & 32)  keyFlag[9] = true;//Z
	if (ButtonMask & 64)  keyFlag[10] = true;//L
	if (ButtonMask & 128) keyFlag[11] = true;//R
	if (ButtonMask & 256) keyFlag[12] = true;//Start

}

void Controller::flagClear()
{
	for each(bool flag in keyFlag)
	{
		flag = false;
	}

}

void Controller::inputJoyStick(int Hz)
{
	glutJoystickFunc(joystick, Hz);//Hz[ms]に一回ジョイスティック入力を受け付ける
}
