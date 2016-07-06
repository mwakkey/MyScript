#pragma once

#include "glsl.h"

//•`‰æ‚ğs‚¤ƒNƒ‰ƒX
class Screen
{
private:
	glManager::GLSL *glsl;
	void display();
	void idle();
	void init();


public:
	Screen();
	~Screen();

	void drawScreen();
};