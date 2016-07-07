#pragma once

#include <vector>

class NeuralNet
{
private:
	std::vector<float> input;
	std::vector<float> output;
	std::vector<std::vector<float>> hidden;

	float activatefunc(float x, float alpha);

public:
	NeuralNet(int input, int output, int hidden, int layer);

	void learning();

};