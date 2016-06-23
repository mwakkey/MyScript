
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/glut.h>
#include "graphics.h"
#include "controller.h"
#include "screen.h"


Screen::Screen()
{
	glsl = new GLSL;
}
Screen::~Screen()
{
	delete(glsl);
}

void Screen::drawScreen()
{
	Graphics::setGL(0, nullptr);

	Controller::inputJoyStick(30);
	glsl->initGlsl("vertex.shader", "fragment.shader");
	glsl->glslOn();

	Graphics::draw();

	glsl->glslOff();

}