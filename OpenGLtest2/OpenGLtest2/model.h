#pragma once
#include "tBuffer.h"
#include "multiVar.h"


struct MyVertex
{
	var3D<float, float, float> vertices;
	var3D<float, float, float> normals;
	var2D<float, float> textures;
};

//モデルデータを表すクラス
class Model
{
private:

public:
	std::vector<MyVertex> myVertex;
	std::vector<int> indices;

	Model() {}
	//Objデータからモデルデータを取得
	Model(TBuffer<var3D<float, float, float>> *vs, TBuffer<var3D<int, int, int>> *fs, TBuffer<var3D<float, float, float>> *vns, TBuffer<var2D<float, float>> *uvs);
	//モデルのワールド座標系における初期位置を設定
	void posInit(float pX,float pY,float pZ);
};