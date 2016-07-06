#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/glut.h>

#include "glManager.h"

#define WIDTH 640
#define HEIGHT 480


//��̓I�ȕ`�揈��
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

//OpenGL�ŕ`�悷�邽�߂̑O�������܂Ƃ߂ď���
void glManager::setGL(int argc, char *argv[])
{
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("�V�F�[�_�[�ŕ`��");
	glutDisplayFunc(glManager::display);
	glutIdleFunc(glManager::idle);

	init();
}

//�`��̃��C������
void glManager::draw()
{
	glutMainLoop();

	return;
}