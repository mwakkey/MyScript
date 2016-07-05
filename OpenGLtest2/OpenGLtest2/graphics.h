#pragma once


#define WIDTH 640
#define HEIGHT 480

//OpenGL描画用の処理をまとめた名前空間
namespace Graphics
{

	void display();
	void idle();
	void init();

	void setGL(int argc, char *argv[]);
	void draw();
};