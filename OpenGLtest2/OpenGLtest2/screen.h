#pragma once

#include "glsl.h"

//描画を行うクラス
class Screen
{
private:
	glManager::GLSL *glsl;

public:
	Screen();
	~Screen();

	void drawScreen();
};