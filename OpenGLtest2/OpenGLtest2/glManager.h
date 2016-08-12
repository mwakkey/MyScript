#pragma once
#include "glVertexBuffer.h"
#include <functional>

namespace glManager
{


	//GLVertexBuffer* glVBO;

	//std::function<void()> myDisp;//‘I‘ğ‚µ‚½ƒ‚ƒfƒ‹‚ğ•\¦‚·‚éŠÖ”
	void drawFace();
	void display();
	void reshape(int w,int h);
	void timer(int value);
	void init(float* hmap);
	void glutCallFunc();
	void glMain(int argc, char *argv[]);


}