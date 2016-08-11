#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "glManager.h"

#define WIDTH 640
#define HEIGHT 480


//��̓I�ȕ`�揈��
void glManager::display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Z�o�b�t�@�̃N���A
	glLoadIdentity();
	gluLookAt(3, 4, 5, 0, 0, 0, 0, 1, 0);//(3,4,5)����(0,0,0)��
										 //���Ă��āA(0,1,0)��
										 //������ƂȂ鎋�_

	std::vector<Model> mlist;
	glVBO->glBufferDraw(GL_DYNAMIC_DRAW, mlist[0]);

	glutSwapBuffers();//�E�B���h�E�ɏo��
}

void glManager::reshape(int w,int h) {
	glViewport(0, 0, w, h);//�r���[�|�[�g(�\���̈�)��ݒ�
	glMatrixMode(GL_PROJECTION);//���̐�(����)�̐ݒ��L���ɂ���
	glLoadIdentity;//�s�񃊃Z�b�g(�I�������s���P�ʍs��ɂ���)
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
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH);
	

	glManager::glsl = new GLSL;
	glsl->initGlsl("glsltest.vert", "glsltest.frag");
	glsl->glslOn();
	
	glManager::glVBO = new GLVertexArray;
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
	delete(glVBO);
	return;
}
