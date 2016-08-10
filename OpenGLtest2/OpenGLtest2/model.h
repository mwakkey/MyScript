#pragma once
#include "tBuffer.h"
#include "multiVar.h"


struct MyVertex
{
	var3D<float, float, float> vertices;
	var3D<float, float, float> normals;
	var2D<float, float> textures;
};

//���f���f�[�^��\���N���X
class Model
{
private:
	int dimension;
	std::vector<float> position;

public:
	std::vector<MyVertex> myVertex;
	std::vector<int> indices;

	Model() {}
	//Obj�f�[�^���烂�f���f�[�^���擾
	Model(TBuffer<var3D<float, float, float>> *vs, TBuffer<var3D<int, int, int>> *fs, TBuffer<var3D<float, float, float>> *vns, TBuffer<var2D<float, float>> *uvs);

	/*
	//���f���f�[�^�̒��S���W������������
	void initPos(const std::vector<float>& pos);
	//���f���f�[�^���ړ�������
	void moveModel(const std::vector<float>& deltaPos);
	*/
};