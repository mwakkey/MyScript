#pragma once
#include <functional>

namespace GameLib {
	class GLManager {
	private:
		GLManager(const int w, const int h, void(*disp)());
		GLManager(const GLManager&);//コピーコンストラクタはprivateで呼べなくする
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