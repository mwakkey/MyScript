#pragma once

#include "glsl.h"

//�`����s���N���X
class Screen
{
private:
	glManager::GLSL *glsl;

public:
	Screen();
	~Screen();

	void drawScreen();
};