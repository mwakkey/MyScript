#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/glut.h>

#include "glManager.h"

#define WIDTH 640
#define HEIGHT 480


//具体的な描画処理
void glManager::display(void)
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

void glManager::idle(void)
{
	glutForceJoystickFunc();
	glutPostRedisplay();
}

void glManager::init()
{
	glewInit();
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glManager::glsl = new GLSL;
	glsl->initGlsl("vertex.shader", "fragment.shader");
}

//OpenGLで描画するための前準備をまとめて処理
void glManager::setGL(int argc, char *argv[])
{
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("シェーダーで描画");
	glutDisplayFunc(glManager::display);
	glutIdleFunc(glManager::idle);

	init();
}

//描画のメイン処理
void glManager::draw()
{
	glutMainLoop();

	return;
}