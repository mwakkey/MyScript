#pragma once

namespace Controller
{
	void setController();
	void flagClear();

	void joystick(unsigned int ButtonMask, int x, int y, int z);
	unsigned int inputJoyStick(int Hz);
	
	unsigned int putDown(unsigned int butonID);
};