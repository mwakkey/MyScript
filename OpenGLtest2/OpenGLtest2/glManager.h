#pragma once
#include "glVertexArray.h"
#include <functional>

namespace glManager
{


	//GLVertexBuffer* glVBO;

	//std::function<void()> myDisp;//選択したモデルを表示する関数
	
	void display();
	void reshape(int w,int h);
	void timer(int value);
	void init();
	void glutCallFunc();
	void glMain(int argc, char *argv[]);


}