#pragma once

#include <vector>
#include <string>


//OBJ�t�@�C�����烂�f���f�[�^��ǂݍ��ރN���X
class Obj
{
private:
	//���_���W��ǂݍ��݁A���f�������p�̃o�b�t�@�Ɋi�[����
	void readVertices(const std::string line, TBuffer<float> *vs);
	//�C���f�b�N�X��ǂݍ��݁A���f�������p�̃o�b�t�@�Ɋi�[����
	void readIndices(const std::string line, TBuffer<int> *fs);
	
	Model* createModel(TBuffer<float> *vs, TBuffer<int> *fs);

public:
	Model* loadObj(const std::string fileName);
};

//���f���f�[�^�ǂݍ��݂̂��߂̃o�b�t�@�N���X
template <typename T>
class TBuffer
{
private:
	std::vector<T> buf;
public:
	void add(T value)
	{
		buf.push_back(value);
	}

	T get(int index)
	{
		return buf.at(index);
	}
};

//���f���f�[�^��\���N���X
class Model
{
private:
	std::vector<float> vertices;
	int numVertices;

public:

};
