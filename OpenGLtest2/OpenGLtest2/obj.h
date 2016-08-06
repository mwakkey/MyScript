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
	static void readVertices2D(const std::string line, TBuffer<float> *vs);
	static void readVertices3D(const std::string line, TBuffer<float> *vs);
	//�C���f�b�N�X��ǂݍ��݁A���f�������p�̃o�b�t�@�Ɋi�[����
	static void readIndices(const std::string line, TBuffer<int> *fs,int figure);

public:

	static Model* loadObj2D(const std::string fileName);
	static Model* loadObj3D(const std::string fileName);

};