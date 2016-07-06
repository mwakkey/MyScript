#pragma once

namespace Controller
{
	//ゲーム内でのキー番号と対応するキーのマップ
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