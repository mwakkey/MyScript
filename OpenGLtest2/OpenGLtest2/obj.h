#pragma once

#include <vector>
#include <string>
#include "tBuffer.h"
#include "model.h"

//OBJ�t�@�C�����烂�f���f�[�^��ǂݍ��ރN���X
class Obj
{
private:
	//���_���W��ǂݍ��݁A���f�������p�̃o�b�t�@�Ɋi�[����
	static void readVertices(const std::string line, TBuffer<float> *vs);
	//�C���f�b�N�X��ǂݍ��݁A���f�������p�̃o�b�t�@�Ɋi�[����
	static void readIndices(const std::string line, TBuffer<int> *fs);
	//�@���x�N�g����ǂݍ���
	static void readNormals(const std::string line, TBuffer<float> *vns);
	//uv���W��ǂݍ���
	static void readUVs(const std::string line, TBuffer<int> *uvs);


public:

	static void loadObj(const std::string fileName, Model* m);

};