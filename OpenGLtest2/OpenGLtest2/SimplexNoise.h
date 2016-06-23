#pragma once
#include <vector>


class SimplexNoise {
private:
	static unsigned int perm[512];
	static unsigned int simplex[64][4];
	static float  grad(int hash, float x);
	static float  grad(int hash, float x, float y);
	static float  grad(int hash, float x, float y, float z);
	static float  grad(int hash, float x, float y, float z, float t);

public:
	SimplexNoise();
	static void setNoiseSeed();
	static float SimplexNoise1D(float x);
	static float SimplexNoise2D(float x, float y);
	static float SimplexNoise3D(float x, float y, float z);
	static float SimplexNoise4D(float x, float y, float z, float w);

	static float SimplexNoiseScaled1D(float x, float s);
	static float SimplexNoiseScaled2D(float x, float y, float s);
	static float SimplexNoiseScaled3D(float x, float y, float z, float s);
	static float SimplexNoiseScaled4D(float x, float y, float z, float w, float s);

	static float SimplexNoiseInRange1D(float x, float rangeMin, float rangeMax);
	static float SimplexNoiseInRange2D(float x, float y, float rangeMin, float rangeMax);
	static float SimplexNoiseInRange3D(float x, float y, float z, float rangeMin, float rangeMax);
	static float SimplexNoiseInRange4D(float x, float y, float z, float w, float rangeMin, float rangeMax);

};
