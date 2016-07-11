#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "glManager.h"
#include "crossProd.h"

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
	glsl->initGlsl("glsltest.vert", "glsltest.frag");
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

//3次元座標の配列を基に3次元空間上にポリゴンを表示する
void glManager::triPolygon3D(const float** pos)
{
	float vec1[3], vec2[3];
	for (int i = 0; i < 3; ++i) {
		vec1[i] = pos[1][i] - pos[0][i];
		vec2[i] = pos[2][i] - pos[0][i];
	}

	glEnable(GL_NORMALIZE);
	glBegin(GL_POLYGON);
	glNormal3fv(MathFunc::CrossProd::cross3D(vec1, vec2));
	glVertex3fv(pos[0]);
	glVertex3fv(pos[1]);
	glVertex3fv(pos[2]);

	glEnd();
	glDisable(GL_NORMALIZE);
}
