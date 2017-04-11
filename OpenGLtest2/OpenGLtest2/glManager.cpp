
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glManager.h"

using namespace GameLib;

GLManager* GLManager::mInstance = 0;
int GLManager::width = 0;
int GLManager::height = 0;
void(*GameLib::GLManager::display)() = 0;

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
//���ɃC���X�^���X������Ă���Ή��������������I��
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

	glMatrixMode(GL_PROJECTION);//���̐�(����)��ݒ肷�郂�[�h�Ɉڂ�
	glLoadIdentity();//�s�񃊃Z�b�g(�I�������s���P�ʍs��ɂ���)
	glOrtho(0, width, 0, height, 10, 0);//���s���e���[�h��2D�`����s��
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

//	glManager::glsl = new GLSL;
//	glsl->initGlsl("glsltest.vert", "glsltest.frag");
//	glsl->glslOn();
}

void GLManager::reshape(int w, int h) {
	glViewport(0, 0, w, h);//�r���[�|�[�g(�\���̈�)��ݒ�
	glMatrixMode(GL_PROJECTION);//���̐�(����)��ݒ肷�郂�[�h�Ɉڂ�
	glLoadIdentity();//�s�񃊃Z�b�g(�I�������s���P�ʍs��ɂ���)
	glOrtho(0, width, 0, height, 10, 0);//���s���e���[�h��2D�`����s��
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GLManager::timer(int value)
{
	glutPostRedisplay();//OpenGL�ɍĕ`���v������
	glutForceJoystickFunc();
	glutTimerFunc(17, GLManager::timer, 0);//17�~���b�o�߂���ƃR�[���o�b�N���s��
}


void GLManager::glutCallFunc()
{
	glutDisplayFunc(display);

//	glutReshapeFunc(reshape);//�E�B���h�E�T�C�Y���ύX���ꂽ�Ƃ��ɌĂ΂��֐�
	glutTimerFunc(17, GLManager::timer, 0);
}

void GLManager::glMain(int argc, char *argv[]) {
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutInit(&argc, argv);
	//�_�u���o�b�t�@�ŉ�ʂ̂��������������
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);//RGBA�ł͂Ȃ�RGB?
	glutCreateWindow("OpenGLTest");
	init();
	glutCallFunc();//�R�[���o�b�N�֐���ݒ�


	glutMainLoop();


//	glsl->glslOff();
//	delete(glsl);
	return;
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



//��̓I�ȕ`�揈��
void glManager::display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Z�o�b�t�@�̃N���A

	
	//myLookAt();//�C���X�^���X���w�肵�Ď��s����

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


	
	//myDisp();//�C���X�^���X���w�肵�Ď��s����

	glutSwapBuffers();//�E�B���h�E�ɏo��
}

void glManager::reshape(int w,int h) {
	glViewport(0, 0, w, h);//�r���[�|�[�g(�\���̈�)��ݒ�
	glMatrixMode(GL_PROJECTION);//���̐�(����)�̐ݒ��L���ɂ���
	glLoadIdentity;//�s�񃊃Z�b�g(�I�������s���P�ʍs��ɂ���)
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

//�`��̃��C������
void glManager::glMain(int argc, char *argv[]){
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInit(&argc, argv);
	//�_�u���o�b�t�@�ŉ�ʂ̂��������������
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