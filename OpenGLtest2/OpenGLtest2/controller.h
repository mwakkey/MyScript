#pragma once

namespace Controller
{
	void setController(int buttons);

	void flagClear();

	void joystick(unsigned int ButtonMask, int x, int y, int z);
	void inputJoyStick(int Hz);
	

};