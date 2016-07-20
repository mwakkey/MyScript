#pragma once

#include <vector>
#include <string>
#include <sstream>      // std::ostringstream


namespace std
{
	//文字列を指定文字で分割
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

	//文字列を数値に変換
	template<class T> T parse(const std::string& src)
	{
		T dst;
		std::istringstream(src) >> dst;
		return dst;
	}

}