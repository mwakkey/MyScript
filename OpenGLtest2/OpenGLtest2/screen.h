#pragma once

#include "glsl.h"

//描画を行うクラス
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