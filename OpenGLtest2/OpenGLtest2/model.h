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
	int dimension;
	std::vector<float> position;

public:
	std::vector<MyVertex> myVertex;
	std::vector<int> indices;

	Model() {}
	//Objデータからモデルデータを取得
	Model(TBuffer<var3D<float, float, float>> *vs, TBuffer<var3D<int, int, int>> *fs, TBuffer<var3D<float, float, float>> *vns, TBuffer<var2D<float, float>> *uvs);

	/*
	//モデルデータの中心座標を初期化する
	void initPos(const std::vector<float>& pos);
	//モデルデータを移動させる
	void moveModel(const std::vector<float>& deltaPos);
	*/
};