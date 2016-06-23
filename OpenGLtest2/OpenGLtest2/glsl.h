#pragma once
#include <GL/glew.h>

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