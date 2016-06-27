#pragma once

namespace Controller
{
	void setController();
	void flagClear();

	void joystick(unsigned int ButtonMask, int x, int y, int z);
	void inputJoyStick(int Hz);
	
	bool putDown(unsigned int butonID);
};