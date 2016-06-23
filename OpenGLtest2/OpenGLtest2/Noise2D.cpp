#include <vector>
#include <math.h>
#include <numeric>
#include "Noise2D.h"

using namespace std;
	
float Noise2D::Interpolate(float from, float to, float percent) {
	float f_out = F(percent);
	return from*(1 - f_out) + to*f_out;
}

float Noise2D::F(float t) {
	return (float)(6.0*pow(t, 5.0) - 15.0*pow(t, 4.0) + 10 * pow(t,3.0));
}

Noise2D::Noise2D() {}
Noise2D::Noise2D(const vector<vector<vector<float>>>& normalised_gradients, int x, int y, float amplitude)
	:m_Gradients(normalised_gradients), m_X(x), m_Y(y), m_Amplitude(amplitude)
{
	;
}

float Noise2D::Amplitude() {
	return m_Amplitude;
}
	
float Noise2D::EvalAt(float x, float y) {
	x *= m_X;
	y *= m_Y;

	int i = (int)x;
	int j = (int)y;


	vector<float> g00 = (m_Gradients[i])[j]; //特定の地点での勾配ベクトル
	auto g10 = (m_Gradients[i+1])[j];
	auto g01 = (m_Gradients[i])[j + 1];
	auto g11 = (m_Gradients[i + 1])[j + 1];

	float u = x - i;
	float v = y - j;

	float n00 = inner_product(g00.begin(),g00.end(), vector<float>{u,v}.begin(),0);
	float n10 = inner_product(g10.begin(), g10.end(), vector<float>{u-1, v}.begin(), 0);
	float n01 = inner_product(g01.begin(), g01.end(), vector<float>{u, v-1}.begin(), 0);
	float n11 = inner_product(g11.begin(), g11.end(), vector<float>{u-1, v-1}.begin(), 0);

	float nx0 = Interpolate(n00, n10, u);
	float nx1 = Interpolate(n01, n11, u);
	float nxy = round(Interpolate(nx0, nx1, v));

	return nxy*m_Amplitude;
}