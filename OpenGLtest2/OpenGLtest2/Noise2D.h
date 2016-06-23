#pragma once
#include <vector>


class Noise2D {
private:
	std::vector<std::vector<std::vector<float>>> m_Gradients;
	int m_X;
	int m_Y;
	float m_Amplitude;


	float Interpolate(float from, float to, float percent);
	float F(float t);

public:
	Noise2D();
	Noise2D(const std::vector<std::vector<std::vector<float>>>& normalised_gradients, int x, int y, float amplitude);

	float Amplitude();

	float EvalAt(float x, float y);

};