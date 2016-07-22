#pragma once
#include "tBuffer.h"

//モデルデータを表すクラス
class Model
{
public:
	Model() {}
	Model(TBuffer<float> *vs, TBuffer<int> *fs);
	std::vector<float> vertices;
};