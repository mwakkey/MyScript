
#include "neuralnet.h"


NeuralNet::NeuralNet(int input, int output, int hidden, int layer)
{
	inLayer.resize(input);		//入力層の次元数
	inLayer.resize(output);		//出力層の次元数
	hidLayer.resize(layer - 2);		//隠れ層のレイヤー数
	for (int i = 0; i < hidLayer.size();++i) {
		hidLayer[i].resize(hidden);	//それぞれの隠れ層の次元数
	}
}


float NeuralNet::activatefunc(float x, float alpha)
{
	return x > 0 ? x : alpha*x; //活性化関数RReLU
}

void NeuralNet::learning()
{
	;
}