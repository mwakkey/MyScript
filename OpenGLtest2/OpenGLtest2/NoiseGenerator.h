#pragma once
#include <vector>
#include "Noise2D.h"
#include "ComplexNoise2D.h"


class NoiseGenerator {
private:
	float CalculateRandamGradientFor();

public:
	NoiseGenerator();

	Noise2D* Generate2D(int x, int y, float amplitude);

	ComplexNoise2D* GenerateComplex2D(int iterations, float persistence, int base_x, int base_y);

};