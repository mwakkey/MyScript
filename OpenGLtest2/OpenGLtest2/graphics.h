#pragma once


#define WIDTH 640
#define HEIGHT 480

//OpenGL�`��p�̏������܂Ƃ߂����O���
namespace Graphics
{

	void display();
	void idle();
	void init();

	void setGL(int argc, char *argv[]);
	void draw();
};