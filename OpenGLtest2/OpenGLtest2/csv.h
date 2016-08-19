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
	void csvWrite(const T** data)
	{
		for (T* dataRow : data) {
			for (T datum : dataRow) {
				output << datum << ",";
			}
			output << std::endl;
		}

	}

	template <typename T>
	void csvWrite(const T* data)
	{
		for (T datum : dataRow) {
			output << datum << ",";
		}

		output << std::endl;
	}
};