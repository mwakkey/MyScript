#pragma once

#include <vector>
#include <string>


//OBJファイルからモデルデータを読み込むクラス
class Obj
{
private:

public:
	Model* loadObj(const std::string fileName);
	void readVertices(const std::string line,TBuffer<float> *vs);
	void readIndices(const std::string line,TBuffer<int> *fs);
	Model* createModel(TBuffer<float> *vs, TBuffer<int> *fs);
};

//モデルデータ読み込みのためのバッファクラス
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

//モデルデータを表すクラス
class Model
{
private:
	std::vector<float> vertices;
	int numVertices;

public:

};
