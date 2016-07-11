#pragma once
#include "glsl.h"

namespace glManager
{
	GLSL* glsl;
	void display();
	void idle();
	void init();
	void setGL(int argc, char *argv[]);
	void draw();

	void triPolygon3D(const float** pos);

}