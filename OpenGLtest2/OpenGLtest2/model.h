#pragma once
#include "tBuffer.h"

//モデルデータを表すクラス
class Model
{
public:
	Model() {}
	Model(TBuffer<float> *vs, TBuffer<int> *fs,int dim);
	std::vector<float> vertices;
};