#pragma once

#include <vector>

class NeuralNet
{
private:
	std::vector<float> inLayer;
	std::vector<float> outLayer;
	std::vector<std::vector<float>> hidLayer;

	float activatefunc(float x, float alpha);

public:
	NeuralNet(int input, int output, int hidden, int layer);

	void learning();

};