#pragma once
#include "glsl.h"
#include "glVertexArray.h"

namespace glManager
{

	GLSL* glsl;
	GLVertexArray* glVBO;

	void display();
	void idle();
	void init();
	void setGL(int argc, char *argv[]);
	void glMain();


}