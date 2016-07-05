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
		for (std::vector<T> dataRow : data) {
			for (int i = 0; i < dataRow.size();++i) {
				output << dataRow[i];
				if (i < dataRow.size() - 1) {
					output << ",";
				}
			}
			output << std::endl;
		}

	}
};