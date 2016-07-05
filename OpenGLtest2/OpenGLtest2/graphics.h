#pragma once


#define WIDTH 640
#define HEIGHT 480

//OpenGL•`‰æ—p‚Ìˆ—‚ğ‚Ü‚Æ‚ß‚½–¼‘O‹óŠÔ
namespace Graphics
{

	void display();
	void idle();
	void init();

	void setGL(int argc, char *argv[]);
	void draw();
};