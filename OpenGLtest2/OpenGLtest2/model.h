#pragma once
#include "tBuffer.h"

//���f���f�[�^��\���N���X
class Model
{
private:
	int dimension;
	std::vector<float> position;

public:
	Model() {}
	//Obj�f�[�^���烂�f���f�[�^���擾
	Model(TBuffer<float> *vs, TBuffer<int> *fs, int dim);

	//���f���f�[�^�̒��S���W������������
	void initPos(const std::vector<float>& pos);
	//���f���f�[�^���ړ�������
	void moveModel(const std::vector<float>& deltaPos);

	std::vector<float> vertices;
};