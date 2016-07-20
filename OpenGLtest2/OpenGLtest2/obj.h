#pragma once

#include <vector>
#include <string>

#define DEF_BUF_SIZE 2


//OBJファイルからモデルデータを読み込むクラス
class Obj
{
private:
	TBuffer<float> *vs;
	TBuffer<int> *fs;

public:
	Obj();
	~Obj();
	Model* loadObj(const std::string fileName);
	void readVertices(const std::string line);
	void readIndices(const std::string line);
	Model* createModel();
};

//モデルデータ読み込みのためのバッファクラス
template <typename T>
class TBuffer
{
private:
	int bufSize;
	std::vector<T> buf;
public:
	TBuffer()
	{
		bufSize = DEF_BUF_SIZE;
		buf.resize(bufSize);
	}
	void add(T value)
	{
		buf.push_back(value);
	}

	T get(int index)
	{
		return buf.at(index);
	}
};

//モデルデータを表すクラス
class Model
{
private:
	std::vector<float> vertices;
	int numVertices;

public:

};
