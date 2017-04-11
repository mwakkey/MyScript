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
	//�ꎟ���f�[�^��csv��
	template <class T>
	void csvWrite(const std::vector<T>& data)
	{
		for (auto datum : data) {
			output << datum << delimiter;
		}

		output << std::endl;
	}

	//�񎟌��f�[�^��csv��
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

	//�ꎟ���f�[�^��0�����f�[�^�̘A��csv��
	template <class A, class B>
	void csvWrite(const std::vector<A>& dataA, const B dataB)
	{
		for (int i = 0; i < dataA.size(); ++i) {
			output << dataA[i] << delimiter;
		}
		output << dataB << delimiter << std::endl;
	}

	//�قȂ���ނ�1�����f�[�^�̑Δ�csv��
	template <class A, class B>
	void csvWrite(const std::vector<A>& dataA, const std::vector<B>& dataB)
	{
		for (int i = 0; i < dataA.size(); ++i) {
			output << dataA[i] << delimiter << dataB[i] << delimiter << std::endl;
		}
	}

	//�񎟌��f�[�^�ƈقȂ�1�����f�[�^�̘A���Δ�csv��
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

	//�قȂ���ނ̓񎟌��f�[�^�̑Δ�csv��
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

	//�����^��n��ނ̓񎟌��f�[�^�̑Δ�csv��
	//data:[�񎟌��f�[�^�̌�][�s��][�f�[�^�������̗�]
	template<class T>
	void csvWrite(const std::vector<std::vector<std::vector<T>>>& data)
	{
		for (int row = 0; row < data[0].size(); ++row) {//�s�����w��
			for (int num = 0; num < data.size(); ++num) {//�񎟌��f�[�^�̌����J��Ԃ�
				for (int col = 0; col < data[0][0].size(); ++col) {
					output << data[num][row][col] << delimiter;//1�̂�1�s���̃f�[�^���o��
				}
				output << delimiter;//���̌̂Ɉڂ�
			}
			output << std::endl;//���̍s�Ɉڂ�
		}
	}
	

};