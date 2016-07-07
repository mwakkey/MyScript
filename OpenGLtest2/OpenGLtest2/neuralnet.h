#pragma once

#include <vector>

class NeuralNet
{
private:
	std::vector<float> inLayer;
	std::vector<float> outLayer;
	std::vector<std::vector<float>> hidLayer;
	std::vector<std::vector<std::vector<float>>> weight;

	float activateFunc(float x, float alpha);
	void backpropagation();
	//�f�[�^����
	//�e�w�ɂ���
	//	z=0
	//	���̑w�̊e�j���[�����ɂ���
	//		���̑w���o�͑w�łȂ����
	//			���̑w�̊e�j���[�����ɂ���(�����lb)
	//				+=���݂̑w�̃j���[�����̊����F(���ݑw�̏o�͊���*�j���[�����Ԃ̏d��)
	//%%�o�͑w�ɓ��B����
	//for i=0;�o�͑w�̃j���[�������܂�
	//	delta[i]=(���̃j���[�����̊������֐����o�͒l�ɓK�p��������)*(���̃j���[�����̏o��-���t���)
	//for �O�̊e�w�ɂ���
	//	for i=0;���̑w�̃j���[������-1�܂�
	//		unit=���̑w��i�Ԗڂ̃j���[����
	//		b(_unit) = b - trainingRate * delta[i]
	//	���̑w�����͑w�łȂ����
	//		for j=0;��O�̑w�̃j���[������-1�܂�
	//			unit=��O�̑w��j�Ԗڂ̃j���[����
	//			for k=0;���̑w�̃j���[������-1�܂�
	//				sigma = sigma+delta[k]*(�j���[����j����k�ւ̏d��)
	//			delta[j] = �j���[����j�̊������֐�*sigma
	//			(�j���[����j����i�ւ̏d��) = (�j���[����j����i�ւ̏d��)-trainingRate*delta[j]*��O�̑w�̊���

public:
	NeuralNet(int input, int output, int hidden, int layer);

	void learning();

};