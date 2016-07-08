
#include "neuralnet.h"


NeuralNet::NeuralNet(int input, int output, int hidden, int layer)
{
	inLayer.resize(input);		//���͑w�̎�����
	inLayer.resize(output);		//�o�͑w�̎�����
	hidLayer.resize(layer - 2);		//�B��w�̃��C���[��
	for (int i = 0; i < hidLayer.size();++i) {
		hidLayer[i].resize(hidden);	//���ꂼ��̉B��w�̎�����
	}
}


float NeuralNet::activateFunc(float x, float alpha)
{
	return x > 0 ? x : alpha*x; //�������֐�RReLU
}

void NeuralNet::learning()
{
	;
}