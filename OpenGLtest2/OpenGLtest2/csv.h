#pragma once

#include <fstream>
#include <vector>

class CSV
{
private:
	std::ofstream output;

public:
	CSV();
	CSV(const char* csvFile);
	~CSV();
	
	template <typename T>
	void csvWrite(const std::vector<std::vector<T>>& data)
	{
		for (auto dataRow : data) {
			for (auto datum : dataRow) {
				output << datum << ",";
			}
			output << std::endl;
		}

	}
};