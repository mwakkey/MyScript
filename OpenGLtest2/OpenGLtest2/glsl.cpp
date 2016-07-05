#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include "glsl.h"
#include <stdio.h>

#include <GL/glut.h>

//��̓I�ȕ`�揈��
void glManager::display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, WIDTH, HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, WIDTH / HEIGHT, 0.1, 2000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glutSwapBuffers();
}

void glManager::idle(void)
{
	glutForceJoystickFunc();
	glutPostRedisplay();
}

void glManager::init()
{
	glewInit();
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

}


//OpenGL�ŕ`�悷�邽�߂̑O�������܂Ƃ߂ď���
void glManager::setGL(int argc, char *argv[])
{
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("�V�F�[�_�[�ŕ`��");
	glutDisplayFunc(glManager::display);
	glutIdleFunc(glManager::idle);

	glManager::init();
}

//�`��̃��C������
void glManager::draw()
{
	glutMainLoop();

	return;
}



glManager::GLSL::~GLSL()
{
	glDeleteProgram(shaderProg);
}

//shader file��ǂݍ��݃R���p�C������	
void glManager::GLSL::readShaderCompile(GLuint shader, const char *file)
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
void glManager::GLSL::link(GLuint prog)
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
void glManager::GLSL::initGlsl(const char *vertexFile)
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


void glManager::GLSL::initGlsl(const char *vertexFile, const char *fragmentFile)
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


void glManager::GLSL::glslOn()
{
	glUseProgram(shaderProg);
}

void glManager::GLSL::glslOff()
{
	glUseProgram(0);
}
