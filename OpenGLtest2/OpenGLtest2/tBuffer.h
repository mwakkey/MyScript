#pragma once
#include <vector>

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