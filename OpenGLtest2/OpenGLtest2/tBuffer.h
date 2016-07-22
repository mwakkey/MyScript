#pragma once
#include <vector>

//���f���f�[�^�ǂݍ��݂̂��߂̃o�b�t�@�N���X
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