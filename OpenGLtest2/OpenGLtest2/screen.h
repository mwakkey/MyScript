#pragma once

#include "glsl.h"

//•`‰æ‚ğs‚¤ƒNƒ‰ƒX
class Screen
{
private:
	glManager::GLSL *glsl;

public:
	Screen();
	~Screen();

	void drawScreen();
};