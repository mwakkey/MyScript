#pragma once
#include <functional>

namespace GL {
	//OpenGL�̏����̗�����Ǘ�
	class GLManager {
	private:
		GLManager(const int w, const int h, void(*disp)());
		GLManager(const GLManager&);//�R�s�[�R���X�g���N�^��private�ŌĂׂȂ�����
		~GLManager();
		GLManager &operator=(const GLManager&) {}

		static GLManager* mInstance;

		static int width, height;
		static void (*display)();

		static void init();
		static void glutCallFunc();
		static void reshape(int w, int h);
		static void timer(int t);

	public:
		static GLManager* instance();
		static void createGameManager(const int w, const int h, void (*disp)());
		static void destroyGameManager();

		void glMain(int argc, char *argv[]);
	};

	//�e�N�X�`���֌W(TBO)�͌��
	void createVBO(GLuint,const float[], GLuint,const float[]);
	void deleteVBO(GLuint, GLuint);
	void drawVBO(GLuint, GLuint, int);
	void modifyVBO(GLuint, float[]);
}



/*
namespace glManager
{
	void display();
	void reshape(int w,int h);
	void timer(int value);
	void init();
	void glutCallFunc();
	void glMain(int argc, char *argv[]);
}

*/