#include <vector>
#include "NoiseGenerator.h"
#include "Noise2D.h"
#include "ComplexNoise2D.h"
#include "XorShift.h"

using namespace std;

NoiseGenerator::NoiseGenerator()
{
	MathFunc::xorShift(123456789, 371957024);
}

//�����_���Ȍ��z���o�͂���
float NoiseGenerator::CalculateRandamGradientFor()
{
	return MathFunc::rand(0, 10000) / 10000.0f;//float [0,1)
}
	
Noise2D* NoiseGenerator::Generate2D(int x, int y,float amplitude) {
	// ��ԉE�̗�ƈ�ԉ��̍s�ɂ���R���g���[���|�C���g�Əd�˂�|�W�V�����̃m�C�Y�l��
	// �v�Z���邽�߂ɁAx��y�������R���g���[���|�C���g�����������Ă����܂�
	++x;
	++y;
	vector<vector<vector<float>>> gradients(x, vector<vector<float>>(y, vector<float>(2)));

	for (auto i = 0; i < x; ++i) {
		for (auto j = 0; j < y; ++j) {
			(gradients[i])[j][0] = CalculateRandamGradientFor();
			(gradients[i])[j][1] = CalculateRandamGradientFor();
		}
	}

	return new Noise2D(gradients, x, y, amplitude);
}

ComplexNoise2D* NoiseGenerator::GenerateComplex2D(int iterations, float persistence, int base_x, int base_y) {
	vector<Noise2D> noises(iterations);

	if (iterations < 1) {
		throw new exception("You need to at least iterate once!");
	}

	for (int i = 0; i < iterations;++i) {
		int freqency = (int)(pow(2.0, i) + 0.5);
		float amplitude = (float)pow(persistence, i);

		int x = freqency*base_x;
		int y = freqency*base_y;
		
		Noise2D* tmp = Generate2D(x, y, amplitude);
		noises[i] = *tmp;
		delete tmp;
	}
	
	return new ComplexNoise2D(noises);
}