#pragma once
#include "glVertexArray.h"
#include <functional>

namespace glManager
{

	void display();
	void reshape(int w,int h);
	void timer(int value);
	void init();
	void glutCallFunc();
	void glMain(int argc, char *argv[]);


}