#pragma once

#include <vector>
#include <string>
#include "tBuffer.h"
#include "model.h"

//OBJファイルからモデルデータを読み込むクラス
class Obj
{
private:
	//頂点座標を読み込み、モデル生成用のバッファに格納する
	static void readVertices(const std::string line, TBuffer<float> *vs);
	//インデックスを読み込み、モデル生成用のバッファに格納する
	static void readIndices(const std::string line, TBuffer<int> *fs, int figure);
	
public:

	static Model* loadObj(const std::string fileName);
};
/*
//モデルデータ読み込みのためのバッファクラス
template <typename T>
class TBuffer
{
private:
	std::vector<T> buf;
public:
	int bufSize()
	{
		return buf.size();
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
*/

/*
//モデルデータを表すクラス
class Model
{
public:
	Model() {}
	Model(TBuffer<float> *vs,TBuffer<int> *fs);
	std::vector<float> vertices;
};
*/