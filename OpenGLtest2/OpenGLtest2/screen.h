#pragma once

#include "glsl.h"

//�`����s���N���X
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