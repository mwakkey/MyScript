
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glManager.h"

using namespace GL;

GLManager* GLManager::mInstance = 0;
int GLManager::width = 0;
int GLManager::height = 0;
void(*GL::GLManager::display)() = 0;

GLManager::GLManager(const int w, const int h, void(*disp)()){
	width = w;
	height = h;
	display = disp;
}
GLManager::~GLManager() {
	;
}

GLManager* GLManager::instance() {
	return mInstance;
}

void GLManager::createGameManager(const int w, const int h, void(*disp)()) {
//既にインスタンス化されていれば何もせず処理を終了
	if (!mInstance) {
		mInstance = new GLManager(w, h, disp);
	}
}

void GLManager::destroyGameManager() {
	delete mInstance;
	mInstance = 0;
}

void GLManager::init() {
//	glewInit();
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH);

	glMatrixMode(GL_PROJECTION);//視体積(視野)を設定するモードに移る
	glLoadIdentity();//行列リセット(選択した行列を単位行列にする)
	glOrtho(0, width, 0, height, 10, 0);//平行投影モードで2D描画を行う
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

//	glManager::glsl = new GLSL;
//	glsl->initGlsl("glsltest.vert", "glsltest.frag");
//	glsl->glslOn();
}

void GLManager::reshape(int w, int h) {
	glViewport(0, 0, w, h);//ビューポート(表示領域)を設定
	glMatrixMode(GL_PROJECTION);//視体積(視野)を設定するモードに移る
	glLoadIdentity();//行列リセット(選択した行列を単位行列にする)
	glOrtho(0, width, 0, height, 10, 0);//平行投影モードで2D描画を行う
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GLManager::timer(int value)
{
	glutPostRedisplay();//OpenGLに再描画を要請する
	glutForceJoystickFunc();
	glutTimerFunc(17, GLManager::timer, 0);//17ミリ秒経過するとコールバックを行う
}


void GLManager::glutCallFunc()
{
	glutDisplayFunc(display);

//	glutReshapeFunc(reshape);//ウィンドウサイズが変更されたときに呼ばれる関数
	glutTimerFunc(17, GLManager::timer, 0);
}

void GLManager::glMain(int argc, char *argv[]) {
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutInit(&argc, argv);
	//ダブルバッファで画面のちらつきを解消する
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);//RGBAではなくRGB?
	glutCreateWindow("OpenGLTest");
	init();
	glutCallFunc();//コールバック関数を設定


	glutMainLoop();


//	glsl->glslOff();
//	delete(glsl);
	return;
}

void GL::createVBO(GLuint vrtVBO,const float vertices[], GLuint idxVBO,const float indices[]) {
	glGenBuffers(1, &vrtVBO);
	glBindBuffer(GL_ARRAY_BUFFER, vrtVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	glGenBuffers(1, &idxVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
}

void GL::deleteVBO(GLuint vrtVBO, GLuint idxVBO) {
	glDeleteBuffers(1, &vrtVBO);
	glDeleteBuffers(1, &idxVBO);
}


void GL::drawVBO(GLuint vrtVBO, GLuint idxVBO, int dim) {
	glBindBuffer(GL_ARRAY_BUFFER, vrtVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, idxVBO);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(dim, GL_FLOAT, 0, 0);//データのポインタは0(オフセット0)

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);//データのポインタは0(オフセット0)

	glDisableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void GL::modifyVBO(GLuint vrtVBO, float newVertices[]) {
	glBindBuffer(GL_ARRAY_BUFFER, vrtVBO);
	float* tmp = reinterpret_cast<float*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	tmp = newVertices;

	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


/*
#include "glsl.h"
#include "camera.h"
#include "gameManager.h"
#include "glManager.h"
#include <functional>

#define WIDTH 640
#define HEIGHT 480


namespace glManager {
	GLSL* glsl;
	auto myDisp = std::mem_fn(&GameManager::draw);
	auto myLookAt = std::mem_fn(&Camera::lookAt);
}



//具体的な描画処理
void glManager::display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Zバッファのクリア

	
	//myLookAt();//インスタンスを指定して実行する

	glBegin(GL_LINES);
	glColor3d(0, 1, 0);//x
	glVertex2d(-100, 0);
	glVertex2d(100, 0);

	glColor3d(1, 0, 0);//y
	glVertex2d(0, 0);
	glVertex2d(0, 100);

	glColor3d(0, 0, 1);//z
	glVertex3d(0, 0, -100);
	glVertex3d(0, 0, 100);
	glEnd();


	
	//myDisp();//インスタンスを指定して実行する

	glutSwapBuffers();//ウィンドウに出力
}

void glManager::reshape(int w,int h) {
	glViewport(0, 0, w, h);//ビューポート(表示領域)を設定
	glMatrixMode(GL_PROJECTION);//視体積(視野)の設定を有効にする
	glLoadIdentity;//行列リセット(選択した行列を単位行列にする)
	gluPerspective(30, double(w) / h, 0.1, 400);
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
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH);


	glManager::glsl = new GLSL;
	glsl->initGlsl("glsltest.vert", "glsltest.frag");
	glsl->glslOn();

	
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
	return;
}
*/