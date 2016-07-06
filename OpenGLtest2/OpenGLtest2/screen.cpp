
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/glut.h>
#include "screen.h"


Screen::Screen()
{
	glsl = new glManager::GLSL;
	glManager::display = display;
	glManager::idle = idle;
	glManager::init = init;
}
Screen::~Screen()
{
	delete(glsl);
	glManager::display = nullptr;
	glManager::idle = nullptr;
	glManager::init = nullptr;
}



//‹ï‘Ì“I‚È•`‰æˆ—
void Screen::display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glsl->glslOn();

	glViewport(0, 0, WIDTH, HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, WIDTH / HEIGHT, 0.1, 2000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);



	glsl->glslOff();
	glutSwapBuffers();
}




void Screen::drawScreen()
{
	glManager::setGL(0, nullptr);

	glManager::draw();
}