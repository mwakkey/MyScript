#pragma once
#include <GL/glew.h>

#define WIDTH 640
#define HEIGHT 480

namespace glManager {
	void display();
	void idle();
	void init();
	void setGL(int argc, char *argv[]);
	void draw();

	//�v���O���}�u���V�F�[�_�[�N���X
	class GLSL
	{
	private:
		GLuint shaderProg;
		GLuint vertexShader, fragmentShader;

		//shader file��ǂݍ��݃R���p�C������
		void readShaderCompile(GLuint shader, const char *file);

		//�����N����
		void link(GLuint prog);

	public:
		~GLSL();
		//GLSL�̏�����
		void initGlsl(const char *vertexFile);
		void initGlsl(const char *vertexFile, const char *fragmentFile);

		void glslOn();
		void glslOff();

	};
}