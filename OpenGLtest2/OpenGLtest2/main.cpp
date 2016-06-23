#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <cmath>

#pragma comment(lib, "glut32.lib")
/*
void Point(int x, int y, float size)
{
	glPointSize(size);//�s�N�Z����
	glBegin(GL_POINTS);
	glVertex2i(x, y);//���W
	glEnd();
}

void Line2D(int x1, int y1, int x2, int y2, float size)
{
	glLineWidth(size);
	glBegin(GL_LINES);
	glVertex2i(x1, y1);//�n�_
	glVertex2i(x2, y2);//�I�_
	glEnd();
}

void Square2D(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, float size)
{
	glLineWidth(size);
	glBegin(GL_LINE_LOOP);//�g������
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);
	glEnd();
}

void SquareFill2D(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	glBegin(GL_QUADS);//�h��Ԃ�
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);
	glEnd();
}

void Oval2D(float radius, int x, int y, float ovalx, float ovaly)
{
	float Pai = 3.1415;
	for (float th1 = 0.0; th1 <= 360.0; th1 = th1 + 1.0) {
		float th2 = th1 + 10.0;
		float th1_rad = th1 / 180.0 * Pai;
		float th2_rad = th2 / 180.0 * Pai;

		float x1 = radius * cos(th1_rad)*(ovalx / 100.0f);
		float y1 = radius * sin(th1_rad)*(ovaly / 100.0f);
		float x2 = radius * cos(th2_rad)*(ovalx / 100.0f);
		float y2 = radius * sin(th2_rad)*(ovaly / 100.0f);

		glBegin(GL_LINES);
		glVertex2f(x1 + x, y1 + y);
		glVertex2f(x2 + x, y2 + y);
		glEnd();
	}
}

void Oval2DFill(float radius, int x, int y, float ovalx, float ovaly)
{
	float Pai = 3.1415;
	for (float th1 = 0.0; th1 <= 360.0; th1 = th1 + 1.0) {
		float th2 = th1 + 10.0;
		float th1_rad = th1 / 180.0 * Pai;
		float th2_rad = th2 / 180.0 * Pai;

		float x1 = radius * cos(th1_rad)*(ovalx / 100.0f);
		float y1 = radius * sin(th1_rad)*(ovaly / 100.0f);
		float x2 = radius * cos(th2_rad)*(ovalx / 100.0f);
		float y2 = radius * sin(th2_rad)*(ovaly / 100.0f);

		glBegin(GL_TRIANGLES);
		glVertex2f(x1 + x, y1 + y);
		glVertex2f(x2 + x, y2 + y);
		glEnd();
	}
}

void display()
{
	//glClearColor(0.f, 0.f, 0.f, 1.f);//�f�B�X�v���C���[�h��GLUT_RGBA�̂Ƃ��A
									 //�E�B���h�E�̐F��RGBa�Ŏw��
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor4i(0.0f, 0.0f, 1.0f, 1.0f);
	Point(50, 50, 2.0);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	Point(250, 150, 10.0);
	glFlush();
	//glutSwapBuffers();//�f�B�X�v���C���[�h�Ƀ_�u���o�b�t�@�����O(GLUT_DOUBLE)��
					  //�g���Ƃ��A2�̃o�b�t�@����������
}

void idle(void)
{
	glutPostRedisplay();//OpenGL�ɍĕ`���v������
}

void Init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho(0, 320, 240, 0, -1, 1);//���ˉe���s��(left,right,bottom,top,near,far)
}
void keyboard(unsigned char key, int x, int y)
{
	if (key == 27)exit(0);//ESC�L�[�ŏI��
}

int main(int argc, char* argv[])
{
	glutInitWindowPosition(-200, -500);//�E�B���h�E�̈ʒu���w��
	glutInitWindowSize(640, 480);//�E�B���h�E�̃T�C�Y���w��

	glutInit(&argc, argv);
//	glutGameModeString("640x480:32@60");//��x����:�J���[bit@���t���b�V�����[�g��
										//�Q�[�����[�h�̐ݒ�ɂ���
	glutInitDisplayMode(GLUT_RGBA);
//	glutEnterGameMode();//�Q�[�����[�h�ɂ���(�t���X�N���[���ɂȂ�)

	glutCreateWindow("Hello OpenGL World");//�����ŃE�B���h�E�����w��
										   //�Q�[�����[�h�̂Ƃ��͎g���Ȃ�
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);//���炩���ߒ�`����
							   //�L�[�{�[�h�̃R�[���o�b�N�����𔽉f����
	glutIdleFunc(idle);//�҂����ԂŒ�`�����������s���悤�ݒ肷��
	Init();
	glutMainLoop();

	return 0;
}
*/
#include <vector>
#include <iostream>
#include "PerlinNoise.h"
int main(int argc, char* argv[])
{
	PerlinNoise noise(1, 1, 10, 10, 100, 100);

	std::vector<std::vector<float>> height_map = noise.GetHeightMap();


	for each (auto row in height_map)
	{
		for each(auto col in row)
		{
			std::cout << col << std::endl;
		}
		std::cout << '\n' << std::endl;
	}

	return 0;
}