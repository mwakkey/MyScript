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
}