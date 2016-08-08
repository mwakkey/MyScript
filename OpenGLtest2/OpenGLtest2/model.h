#pragma once
#include "tBuffer.h"

//モデルデータを表すクラス
class Model
{
private:
	int dimension;
	std::vector<float> position;
	std::vector<float> normal;
	std::vector<int> index;
	std::vector<int> uvs;

public:
	Model() {}
	//Objデータからモデルデータを取得
	Model(TBuffer<float> *vs, TBuffer<int> *fs, TBuffer<float> *vns, TBuffer<int> *uvs);

	//モデルデータの中心座標を初期化する
	void initPos(const std::vector<float>& pos);
	//モデルデータを移動させる
	void moveModel(const std::vector<float>& deltaPos);

	std::vector<float> vertices;
};