#pragma once

namespace Controller
{
	void joystick(unsigned int ButtonMask, int x, int y, int z);

	class JoyPad
	{
	private:
		unsigned int myKeyFlag;
		unsigned int keyDown;
		unsigned int keyUp;

	public:
		JoyPad();
		void inputJoyStick(int Hz);
		unsigned int getKey(unsigned int butonID);
		unsigned int getKeyDown(unsigned int buttonID);
		unsigned int getKeyUp(unsigned int buttonID);
	};
};