#pragma once

#include <vector>
#include <string>
#include "tBuffer.h"
#include "model.h"
#include "multiVar.h"

//OBJファイルからモデルデータを読み込むクラス
class ObjLoader
{
private:
	//頂点座標を読み込み、モデル生成用のバッファに格納する
	static void readVertices(const std::string line, TBuffer<var3D<float, float, float>> *vs);
	//インデックスを読み込み、モデル生成用のバッファに格納する
	static void readIndices(const std::string line, TBuffer<var3D<int, int, int>> *fs);
	//法線ベクトルを読み込む
	static void readNormals(const std::string line, TBuffer<var3D<float, float, float>> *vns);
	//uv座標を読み込む
	static void readUVs(const std::string line, TBuffer<var2D<float, float>> *uvs);


public:

	static void loadObj(const std::string fileName, Model* m);

};