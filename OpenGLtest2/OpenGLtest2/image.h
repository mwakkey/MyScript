#pragma once
#include <string>

namespace GameLib{
//画像データをRAW形式で取得し、OpenGLで描画する
	class Image {
	private:
		char* texture;
//		int channel;//RGBやRGBaなどチャネル数
		int iWidth, iHeight;//画像ファイルの縦横サイズ
		int textureID;

		int imageNum;//画像ファイル中のテクスチャ枚数(テクスチャは横一列に並ぶものとする)

	public:
		Image(const std::string, int);
		~Image();

		//読み込んだテクスチャをGPU上に登録する
		void loadImage();

		//positionの範囲にuvで区切った領域のuid番目のテクスチャを貼りつける
		//座標配列は時計回りに(テクスチャ座標は上下逆)
		void draw(float position[], float uv[], int uid);
	};

}