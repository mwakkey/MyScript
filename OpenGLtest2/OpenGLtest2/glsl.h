#pragma once
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#pragma comment(lib, "glew32.lib")
#include <GL/glew.h>


	//プログラマブルシェーダークラス
class GLSL
{
private:
	GLuint shaderProg;
	GLuint vertexShader, fragmentShader;


	//shader fileを読み込みコンパイルする
	void readShaderCompile(GLuint shader, const char *file);

	//リンクする
	void link(GLuint prog);

public:
	~GLSL();
	//GLSLの初期化
	void initGlsl(const char *vertexFile);
	void initGlsl(const char *vertexFile, const char *fragmentFile);

	void glslOn();
	void glslOff();

};