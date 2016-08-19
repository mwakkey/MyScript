#pragma once

#include <vector>
#include <string>
#include <sstream>      // std::stringstream


namespace std
{
	//•¶š—ñ‚ğw’è•¶š‚Å•ªŠ„
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

	//•¶š—ñ‚ğ”’l‚É•ÏŠ·
	template<class T> T parse(const std::string& src)
	{
		T dst;
		std::istringstream(src) >> dst;
		return dst;
	}


	//”CˆÓŒ^‚ğ•¶š—ñ‚É•ÏŠ·‚·‚é
	template <class T> 
	string toString(T& data)
	{
		stringstream str;
		str << data;

		return str.str();
	}
}