#pragma once
#include "tBuffer.h"

//���f���f�[�^��\���N���X
class Model
{
public:
	Model() {}
	Model(TBuffer<float> *vs, TBuffer<int> *fs);
	std::vector<float> vertices;
};