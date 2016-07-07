
#include "glsl.h"
#include <stdio.h>
#include <GL/glut.h>



GLSL::~GLSL()
{
	glDeleteProgram(shaderProg);
}

//shader file��ǂݍ��݃R���p�C������	
void GLSL::readShaderCompile(GLuint shader, const char *file)
{	
	FILE *fp;
	char *buf;
	GLsizei size, len;
	GLint compiled;


	fopen_s(&fp, file, "rb");	// �t�@�C�����J��
	if (!fp) printf("�t�@�C�����J�����Ƃ��ł��܂��� %s\n", file);

	fseek(fp, 0, SEEK_END);//�t�@�C���̖����Ɉړ������݈ʒu�𓾂�
	size = ftell(fp);//�t�@�C���T�C�Y���擾
	buf = (GLchar *)malloc(size);// �t�@�C���T�C�Y�̃��������m��
	if (buf == NULL) {
		printf("���������m�ۂł��܂���ł��� \n");
	}
	fseek(fp, 0, SEEK_SET);	// �t�@�C����擪����ǂݍ���
	fread(buf, 1, size, fp);

	//---------�����܂ŃV�F�[�_�t�@�C���̓ǂݍ���------------------------

		//�V�F�[�_�I�u�W�F�N�g�Ƀv���O�������Z�b�g
	glShaderSource(shader, 1, (const GLchar **)&buf, &size);

	free(buf);//�V�F�[�_�ǂݍ��ݗ̈�̉��
	fclose(fp);

	// �V�F�[�_�̃R���p�C��
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (compiled == GL_FALSE) {
		printf("�R���p�C���ł��܂���ł���!!: %s \n ", file);
		glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &size);
		if (size > 0) {
			buf = (char *)malloc(size);
			glGetShaderInfoLog(shader, size, &len, buf);
			printf(buf);
			free(buf);
		}
	}
}

//�����N����
void GLSL::link(GLuint prog)
{
	GLsizei size, len;
	GLint linked;
	char *infoLog;
	glLinkProgram(prog);//�����N
	glGetProgramiv(prog, GL_LINK_STATUS, &linked);
	if (linked == GL_FALSE) {
		printf("�����N�ł��܂���ł���!! \n");
		glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &size);
		if (size > 0) {
			infoLog = (char *)malloc(size);
			glGetProgramInfoLog(prog, size, &len, infoLog);
			printf(infoLog);
			free(infoLog);
		}
	}
}

//GLSL�̏�����
void GLSL::initGlsl(const char *vertexFile)
{
	//glew�̏�����
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		printf("Error: %s\n", glewGetErrorString(err));
	}
	// GPU,OpenGL���
	printf("VENDOR= %s \n", glGetString(GL_VENDOR));
	printf("GPU= %s \n", glGetString(GL_RENDERER));
	printf("OpenGL= %s \n", glGetString(GL_VERSION));
	printf("GLSL= %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	//�V�F�[�_�[�I�u�W�F�N�g�̍쐬
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//�V�F�[�_�[�̓ǂݍ��݂ƃR���p�C��
	readShaderCompile(vertexShader, vertexFile);
	// �V�F�[�_�v���O�����̍쐬
	shaderProg = glCreateProgram();
	// �V�F�[�_�I�u�W�F�N�g���V�F�[�_�v���O�����Ɋ֘A�t����
	glAttachShader(shaderProg, vertexShader);
	// �V�F�[�_�I�u�W�F�N�g�̍폜
	glDeleteShader(vertexShader);
	// �V�F�[�_�v���O�����̃����N
	link(shaderProg);
}


void GLSL::initGlsl(const char *vertexFile, const char *fragmentFile)
{
	//glew�̏�����
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		printf("Error: %s\n", glewGetErrorString(err));
	}
	// GPU,OpenGL���
	printf("VENDOR= %s \n", glGetString(GL_VENDOR));
	printf("GPU= %s \n", glGetString(GL_RENDERER));
	printf("OpenGL= %s \n", glGetString(GL_VERSION));
	printf("GLSL= %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	//�V�F�[�_�[�I�u�W�F�N�g�̍쐬
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//�V�F�[�_�[�̓ǂݍ��݂ƃR���p�C��
	readShaderCompile(vertexShader, vertexFile);
	readShaderCompile(fragmentShader, fragmentFile);
	// �v���O�����I�u�W�F�N�g�̍쐬
	shaderProg = glCreateProgram();
	// �V�F�[�_�I�u�W�F�N�g���V�F�[�_�v���O�����Ɋ֘A�t����
	glAttachShader(shaderProg, vertexShader);
	glAttachShader(shaderProg, fragmentShader);
	// �V�F�[�_�I�u�W�F�N�g�̍폜
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	// �V�F�[�_�v���O�����̃����N
	link(shaderProg);
}


void GLSL::glslOn()
{
	glUseProgram(shaderProg);
}

void GLSL::glslOff()
{
	glUseProgram(0);
}
