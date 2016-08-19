#pragma once
#include <vector>
#include <string>
#include <fstream>

class CSV
{
private:
	std::ofstream output;
	std::string delimiter;
public:
	CSV();
	CSV(const char* csvFile,std::string dlm);
	~CSV();
	
	void set(const char* csvFile,std::string dlm);
	void reset();
	//一次元データのcsv化
	template <class T>
	void csvWrite(const std::vector<T>& data)
	{
		for (auto datum : data) {
			output << datum << delimiter;
		}

		output << std::endl;
	}

	//二次元データのcsv化
	template <class T>
	void csvWrite(const std::vector<std::vector<T>>& data)
	{
		for (auto dataRow : data) {
			for (auto datum : dataRow) {
				output << datum << delimiter;
			}
			output << std::endl;
		}

	}

	//一次元データと0次元データの連結csv化
	template <class A, class B>
	void csvWrite(const std::vector<A>& dataA, const B dataB)
	{
		for (int i = 0; i < dataA.size(); ++i) {
			output << dataA[i] << delimiter;
		}
		output << dataB << delimiter << std::endl;
	}

	//異なる二種類の1次元データの対比csv化
	template <class A, class B>
	void csvWrite(const std::vector<A>& dataA, const std::vector<B>& dataB)
	{
		for (int i = 0; i < dataA.size(); ++i) {
			output << dataA[i] << delimiter << dataB[i] << delimiter << std::endl;
		}
	}

	//二次元データと異なる1次元データの連結対比csv化
	template <class A, class B>
	void csvWrite(const std::vector<std::vector<A>>& dataA, const std::vector<B>& dataB)
	{
		for (int i = 0; i < dataB.size(); ++i) {
			for (auto datum : dataA[i]) {
				output << datum << delimiter;
			}
			output << dataB[i] << delimiter << std::endl;
		}
	}

	//異なる二種類の二次元データの対比csv化
	template <class A, class B>
	void csvWrite(const std::vector<std::vector<A>>& dataA, const std::vector<std::vector<B>>& dataB)
	{
		for (int i = 0; i < dataA.size(); ++i) {
			for (int j = 0; j < dataA[i].size(); ++j) {
				output << dataA[i][j] << delimiter;
			}
			output << delimiter;
			for (int j = 0; j < dataB[i].size(); ++j) {
				output << dataB[i][j] << delimiter;
			}
			output << std::endl;
		}
	}

	//同じ型のn種類の二次元データの対比csv化
	//data:[二次元データの個数][行数][データ一個あたりの列数]
	template<class T>
	void csvWrite(const std::vector<std::vector<std::vector<T>>>& data)
	{
		for (int row = 0; row < data[0].size(); ++row) {//行数を指定
			for (int num = 0; num < data.size(); ++num) {//二次元データの個数分繰り返す
				for (int col = 0; col < data[0][0].size(); ++col) {
					output << data[num][row][col] << delimiter;//1個体の1行分のデータを出力
				}
				output << delimiter;//次の個体に移る
			}
			output << std::endl;//次の行に移る
		}
	}
	

};