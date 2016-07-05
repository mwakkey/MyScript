#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include "glsl.h"
#include <stdio.h>

#include <GL/glut.h>

//具体的な描画処理
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


//OpenGLで描画するための前準備をまとめて処理
void glManager::setGL(int argc, char *argv[])
{
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("シェーダーで描画");
	glutDisplayFunc(glManager::display);
	glutIdleFunc(glManager::idle);

	glManager::init();
}

//描画のメイン処理
void glManager::draw()
{
	glutMainLoop();

	return;
}



glManager::GLSL::~GLSL()
{
	glDeleteProgram(shaderProg);
}

//shader fileを読み込みコンパイルする	
void glManager::GLSL::readShaderCompile(GLuint shader, const char *file)
{	
	FILE *fp;
	char *buf;
	GLsizei size, len;
	GLint compiled;


	fopen_s(&fp, file, "rb");	// ファイルを開く
	if (!fp) printf("ファイルを開くことができません %s\n", file);

	fseek(fp, 0, SEEK_END);//ファイルの末尾に移動し現在位置を得る
	size = ftell(fp);//ファイルサイズを取得
	buf = (GLchar *)malloc(size);// ファイルサイズのメモリを確保
	if (buf == NULL) {
		printf("メモリが確保できませんでした \n");
	}
	fseek(fp, 0, SEEK_SET);	// ファイルを先頭から読み込む
	fread(buf, 1, size, fp);

	//---------ここまでシェーダファイルの読み込み------------------------

		//シェーダオブジェクトにプログラムをセット
	glShaderSource(shader, 1, (const GLchar **)&buf, &size);

	free(buf);//シェーダ読み込み領域の解放
	fclose(fp);

	// シェーダのコンパイル
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (compiled == GL_FALSE) {
		printf("コンパイルできませんでした!!: %s \n ", file);
		glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &size);
		if (size > 0) {
			buf = (char *)malloc(size);
			glGetShaderInfoLog(shader, size, &len, buf);
			printf(buf);
			free(buf);
		}
	}
}

//リンクする
void glManager::GLSL::link(GLuint prog)
{
	GLsizei size, len;
	GLint linked;
	char *infoLog;
	glLinkProgram(prog);//リンク
	glGetProgramiv(prog, GL_LINK_STATUS, &linked);
	if (linked == GL_FALSE) {
		printf("リンクできませんでした!! \n");
		glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &size);
		if (size > 0) {
			infoLog = (char *)malloc(size);
			glGetProgramInfoLog(prog, size, &len, infoLog);
			printf(infoLog);
			free(infoLog);
		}
	}
}
//GLSLの初期化
void glManager::GLSL::initGlsl(const char *vertexFile)
{
	//glewの初期化
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		printf("Error: %s\n", glewGetErrorString(err));
	}
	// GPU,OpenGL情報
	printf("VENDOR= %s \n", glGetString(GL_VENDOR));
	printf("GPU= %s \n", glGetString(GL_RENDERER));
	printf("OpenGL= %s \n", glGetString(GL_VERSION));
	printf("GLSL= %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	//シェーダーオブジェクトの作成
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//シェーダーの読み込みとコンパイル
	readShaderCompile(vertexShader, vertexFile);
	// シェーダプログラムの作成
	shaderProg = glCreateProgram();
	// シェーダオブジェクトをシェーダプログラムに関連付ける
	glAttachShader(shaderProg, vertexShader);
	// シェーダオブジェクトの削除
	glDeleteShader(vertexShader);
	// シェーダプログラムのリンク
	link(shaderProg);
}


void glManager::GLSL::initGlsl(const char *vertexFile, const char *fragmentFile)
{
	//glewの初期化
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		printf("Error: %s\n", glewGetErrorString(err));
	}
	// GPU,OpenGL情報
	printf("VENDOR= %s \n", glGetString(GL_VENDOR));
	printf("GPU= %s \n", glGetString(GL_RENDERER));
	printf("OpenGL= %s \n", glGetString(GL_VERSION));
	printf("GLSL= %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	//シェーダーオブジェクトの作成
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//シェーダーの読み込みとコンパイル
	readShaderCompile(vertexShader, vertexFile);
	readShaderCompile(fragmentShader, fragmentFile);
	// プログラムオブジェクトの作成
	shaderProg = glCreateProgram();
	// シェーダオブジェクトをシェーダプログラムに関連付ける
	glAttachShader(shaderProg, vertexShader);
	glAttachShader(shaderProg, fragmentShader);
	// シェーダオブジェクトの削除
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	// シェーダプログラムのリンク
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
