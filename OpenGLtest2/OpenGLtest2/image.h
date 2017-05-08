#pragma once
#include <string>

namespace GL{
//画像データをRAW形式で取得し、OpenGLに登録する
	class Image {
	private:
		char* texture;
//		int channel;//RGBやRGBaなどチャネル数
		int iWidth, iHeight;//画像ファイルの縦横サイズ

	public:
		Image(const std::string, int, int);
		~Image();

		//読み込んだテクスチャをGPU上に登録する
		unsigned int loadImage();
	};

}