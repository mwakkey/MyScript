/*
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <cmath>

#pragma comment(lib, "glut32.lib")

void Point(int x, int y, float size)
{
	glPointSize(size);//ピクセル数
	glBegin(GL_POINTS);
	glVertex2i(x, y);//座標
	glEnd();
}

void Line2D(int x1, int y1, int x2, int y2, float size)
{
	glLineWidth(size);
	glBegin(GL_LINES);
	glVertex2i(x1, y1);//始点
	glVertex2i(x2, y2);//終点
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
	//glClearColor(0.f, 0.f, 0.f, 1.f);//ディスプレイモードがGLUT_RGBAのとき、
									 //ウィンドウの色をRGBaで指定
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor4i(0.0f, 0.0f, 1.0f, 1.0f);
	Point(50, 50, 2.0);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	Point(250, 150, 10.0);
	glFlush();
	//glutSwapBuffers();//ディスプレイモードにダブルバッファリング(GLUT_DOUBLE)を
					  //使うとき、2つのバッファを交換する
}

void idle(void)
{
	glutPostRedisplay();//OpenGLに再描画を要請する
}

void Init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho(0, 320, 240, 0, -1, 1);//正射影を行う(left,right,bottom,top,near,far)
}
void keyboard(unsigned char key, int x, int y)
{
	if (key == 27)exit(0);//ESCキーで終了
}

int main(int argc, char* argv[])
{
	glutInitWindowPosition(-200, -500);//ウィンドウの位置を指定
	glutInitWindowSize(640, 480);//ウィンドウのサイズを指定

	glutInit(&argc, argv);
//	glutGameModeString("640x480:32@60");//幅x高さ:カラーbit@リフレッシュレートを
										//ゲームモードの設定にする
	glutInitDisplayMode(GLUT_RGBA);
//	glutEnterGameMode();//ゲームモードにする(フルスクリーンになる)

	glutCreateWindow("Hello OpenGL World");//引数でウィンドウ名を指定
										   //ゲームモードのときは使えない
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);//あらかじめ定義した
							   //キーボードのコールバック処理を反映する
	glutIdleFunc(idle);//待ち時間で定義した処理を行うよう設定する
	Init();
	glutMainLoop();

	return 0;
}
*/

#include <iostream>
#include <vector>
#include <numeric>
#include "SimplexNoise.h"
#include "csv.h"
int main()
{
	/*
	std::cout << std::endl;
	//SimplexNoise::setNoiseSeed();
	

	std::vector<int> length = {100,100,100};
	int mapLength = std::accumulate(length.begin(), length.end(), 1, std::multiplies<int>());
	std::vector<float> height;
	height.resize(mapLength);

	
	for (int i = 0; i < mapLength; ++i) {
		int j = i / length[1];
		int k = j / length[2];
		height[i] = SimplexNoise::SimplexNoiseInRange3D(2.1f*i, 6.7f*j, 2.7f*k, -100.0f, 100.0f);
		std::cout << height[i] << std::flush;
	}
	std::cout << std::endl;
	*/


	/*
	CSV csv("test.csv");
	std::vector<std::vector<float>> data = { {0.4f,0.8f,0.3f},{0.04f,0.001f,0.8f},{0.6f,0.5f,0.7f} };
	csv.csvWrite(data);
	*/

	return 0;
}