#pragma once

#include <vector>
#include <string>
#include "tBuffer.h"
#include "model.h"

//OBJファイルからモデルデータを読み込むクラス
class Obj
{
private:
	//頂点座標を読み込み、モデル生成用のバッファに格納する
	static void readVertices2D(const std::string line, TBuffer<float> *vs);
	static void readVertices3D(const std::string line, TBuffer<float> *vs);
	//インデックスを読み込み、モデル生成用のバッファに格納する
	static void readIndices(const std::string line, TBuffer<int> *fs,int figure);

public:

	static Model* loadObj2D(const std::string fileName);
	static Model* loadObj3D(const std::string fileName);

};