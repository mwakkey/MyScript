#pragma once

#include "glsl.h"

//•`‰æ‚ğs‚¤ƒNƒ‰ƒX
class Screen
{
private:
	GLSL *glsl;

public:
	Screen();
	~Screen();

	void drawScreen();
};