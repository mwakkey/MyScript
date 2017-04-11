#pragma once

#include <vector>
#include <string>
#include <sstream>      // std::stringstream


namespace std
{
	//��������w�蕶���ŕ���
	std::vector<std::string> split(const std::string &str, char sep)
	{
		std::vector<std::string> v;
		std::stringstream ss(str);
		std::string buffer;
		while (std::getline(ss, buffer, sep)) {
			v.push_back(buffer);
		}
		return v;
	}

	//������𐔒l�ɕϊ�
	template<class T> T parse(const std::string& src)
	{
		T dst;
		std::istringstream(src) >> dst;
		return dst;
	}


	//�C�ӌ^�𕶎���ɕϊ�����
	template <class T> 
	string toString(T& data)
	{
		stringstream str;
		str << data;

		return str.str();
	}
}