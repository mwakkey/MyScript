#pragma once
#include "glVertexBuffer.h"
#include <functional>

namespace glManager
{


	//GLVertexBuffer* glVBO;

	//std::function<void()> myDisp;//�I���������f����\������֐�

	void display();
	void reshape(int w,int h);
	void timer(int value);
	void init();
	void glutCallFunc();
	void glMain(int argc, char *argv[]);


}