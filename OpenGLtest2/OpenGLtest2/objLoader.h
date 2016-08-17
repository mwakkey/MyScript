#pragma once

#include <vector>
#include <string>
#include "tBuffer.h"
#include "model.h"
#include "multiVar.h"

//OBJ�t�@�C�����烂�f���f�[�^��ǂݍ��ރN���X
class ObjLoader
{
private:
	//���_���W��ǂݍ��݁A���f�������p�̃o�b�t�@�Ɋi�[����
	static void readVertices(const std::string line, TBuffer<var3D<float, float, float>> *vs);
	//�C���f�b�N�X��ǂݍ��݁A���f�������p�̃o�b�t�@�Ɋi�[����
	static void readIndices(const std::string line, TBuffer<var3D<int, int, int>> *fs);
	//�@���x�N�g����ǂݍ���
	static void readNormals(const std::string line, TBuffer<var3D<float, float, float>> *vns);
	//uv���W��ǂݍ���
	static void readUVs(const std::string line, TBuffer<var2D<float, float>> *uvs);


public:

	static void loadObj(const std::string fileName, Model* m);

};