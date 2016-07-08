
#include "neuralnet.h"


NeuralNet::NeuralNet(int input, int output, int hidden, int layer)
{
	inLayer.resize(input);		//“ü—Í‘w‚ÌŸŒ³”
	inLayer.resize(output);		//o—Í‘w‚ÌŸŒ³”
	hidLayer.resize(layer - 2);		//‰B‚ê‘w‚ÌƒŒƒCƒ„[”
	for (int i = 0; i < hidLayer.size();++i) {
		hidLayer[i].resize(hidden);	//‚»‚ê‚¼‚ê‚Ì‰B‚ê‘w‚ÌŸŒ³”
	}
}


float NeuralNet::activateFunc(float x, float alpha)
{
	return x > 0 ? x : alpha*x; //Šˆ«‰»ŠÖ”RReLU
}

void NeuralNet::learning()
{
	;
}