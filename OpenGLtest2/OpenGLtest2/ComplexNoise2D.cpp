#include <vector>
#include "Noise2D.h"
#include "ComplexNoise2D.h"

using namespace std;

ComplexNoise2D::ComplexNoise2D(const vector<Noise2D> &noises)
	:m_Noises(noises)
{
	for each  (Noise2D noise in noises)
	{
		m_TotalAmplitude += noise.Amplitude();	
	}
}
	
float ComplexNoise2D::EvalAt(float x, float y) {
	float result = 0.0;
	for each (Noise2D noise in m_Noises)
	{
		result += noise.EvalAt(x, y);
	}

	return (result + m_TotalAmplitude) / (m_TotalAmplitude * 2);
}