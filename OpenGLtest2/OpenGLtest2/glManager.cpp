#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glsl.h"
#include "glManager.h"
#include "SimplexNoise.h"

#define WIDTH 640
#define HEIGHT 480


namespace glManager {
	GLSL* glsl;
}

//具体的な描画処理
void glManager::display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Zバッファのクリア
	glLoadIdentity();
	gluLookAt(-50, 50, 0, 0, 0, 0, 0, 1, 0);//(3,4,5)から(0,0,0)を
										 //見ていて、(0,1,0)が
										 //上向きとなる視点

	
	float heightmap[100][100];
	for (int i = 0; i < 100; ++i) {
		for (int j=0; j < 100; ++j) {
			heightmap[i][j] = SimplexNoise::SimplexNoiseInRange2D(i*1.005f, j*1.005f, -10.0f, 10.0f);
		}
	}

	glBegin(GL_QUADS);
	/*
	for (int i = 0; i < 99; ++i) {
		for (int j = 0; j < 99; ++j) {
			glVertex3f(i, j, heightmap[i][j]);
			glVertex3f(i+1, j, heightmap[i+1][j]);
			glVertex3f(i+1, j+1, heightmap[i+1][j+1]);
			glVertex3f(i, j+1, heightmap[i][j+1]);
		}
	}
	*/
	glVertex3f(1, 1, 1);
	glVertex3f(4, 1, 3);
	glVertex3f(4, 4, -3);
	glVertex3f(1, 4, 5);
	glEnd();


//myDisp();
	//glVBO->glVBODraw(GL_STREAM_DRAW);//mlistに登録したモデルを描画する

	glutSwapBuffers();//ウィンドウに出力
}

void glManager::reshape(int w,int h) {
	glViewport(0, 0, w, h);//ビューポート(表示領域)を設定
	glMatrixMode(GL_PROJECTION);//視体積(視野)の設定を有効にする
	glLoadIdentity;//行列リセット(選択した行列を単位行列にする)
	gluPerspective(30, double(w) / h, 0.1, 200);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void glManager::timer(int t)
{
	glutPostRedisplay();
	glutForceJoystickFunc();
	glutTimerFunc(t, glManager::timer, 17);
}

void glManager::init()
{
	glewInit();
	glClearColor(0.0, 0.0, 0.0, 0.1);
	glEnable(GL_DEPTH);
	

	glManager::glsl = new GLSL;
	glsl->initGlsl("glsltest.vert", "glsltest.frag");
	glsl->glslOn();
	
	//glManager::glVBO = new GLVertexBuffer;
}



void glManager::glutCallFunc()
{
	glutDisplayFunc(glManager::display);
	glutReshapeFunc(glManager::reshape);
	glutTimerFunc(0, glManager::timer, 17);	
}

//描画のメイン処理
void glManager::glMain(int argc, char *argv[]){
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInit(&argc, argv);
	//ダブルバッファで画面のちらつきを解消する
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("OpenGLTest");
	init();

	glutCallFunc();

	glutMainLoop();


	glsl->glslOff();
	delete(glsl);
	//delete(glVBO);
	return;
}
