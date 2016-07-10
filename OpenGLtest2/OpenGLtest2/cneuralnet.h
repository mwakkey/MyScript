#pragma once

#include <vector>

class ConvolutionalNeuralNet
{
private:
	int convSize;
	int convNum;
	int convLayerNum;
	int poolSize;
	int poolLayerNum;
	int LayersNum;

	int fulConvSize;
	int fulConvLayerNum;
	int outputSize;


	float** inLayer;
	std::vector<std::vector<float**>> convLayer(convLayerNum,std::vector<float**>(convNum,float[convSize][convSize]));
	std::vector<std::vector<float**>> poolLayer;
	std::vector<float*> fulConLayer;
	std::vector<float> outLayer;

	float activateFunc(float x);


public:
	ConvolutionalNeuralNet();
	void input(const float** inputData);
};