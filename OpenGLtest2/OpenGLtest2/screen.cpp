
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/glut.h>"
#include "screen.h"


Screen::Screen()
{
	glsl = new glManager::GLSL;
}
Screen::~Screen()
{
	delete(glsl);
}

void Screen::drawScreen()
{
	glManager::setGL(0, nullptr);


	glsl->initGlsl("vertex.shader", "fragment.shader");
	glsl->glslOn();

	glManager::draw();

	glsl->glslOff();

}