#pragma once

#include "glsl.h"

//�`����s���N���X
class Screen
{
private:
	GLSL *glsl;

public:
	Screen();
	~Screen();

	void drawScreen();
};