#pragma once
#include "glsl.h"
#include "glVertexArray.h"

namespace glManager
{

	GLSL* glsl;
	GLVertexArray* glVBO;

	void display();
	void reshape(int w,int h);
	void timer(int value);
	void init();
	void glutCallFunc();
	void glMain(int argc, char *argv[]);


}