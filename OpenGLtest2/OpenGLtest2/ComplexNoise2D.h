#pragma once
#include "Noise2D.h"
#include <vector>


class ComplexNoise2D{	
private:	
	std::vector<Noise2D> m_Noises;
	float m_TotalAmplitude;
	
public:	
	ComplexNoise2D(const std::vector<Noise2D>& noises);

	float EvalAt(float x, float y);

};