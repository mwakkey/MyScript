
#include "reactionDiffusion.h"
#include <algorithm>

MathFunc::ReactionDiffusion::ReactionDiffusion(int mapsize)
	:mapsize(mapsize)
{
	float f = 0.03f;
	float k = 0.056f;
	float ru = 0.09f;
	float rv = 0.056f;

	init();
}

MathFunc::ReactionDiffusion::ReactionDiffusion(int mapsize, float f, float k, float ru, float rv)
	:mapsize(mapsize),f(f),k(k),ru(ru),rv(rv)
{
	init();
}

void MathFunc::ReactionDiffusion::init()
{
	u.resize(mapsize);
	v.resize(mapsize);
	u_next.resize(mapsize);
	v_next.resize(mapsize);

	for (int i = 0; i < mapsize; ++i) {
		u[i].resize(mapsize);
		v[i].resize(mapsize);
		u_next[i].resize(mapsize);
		v_next[i].resize(mapsize);
	}

	mapReset();
}

void MathFunc::ReactionDiffusion::mapReset()
{
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			u[i][j] = 0.9f;
			v[i][j] = 0.0f;
			u_next[i][j] = 0.9f;
			v_next[i][j] = 0.0f;
		}
	}

	/*
	const float init_param = 0.3;
	for (int i = 100; i < 140; i++) {
		for (int j = 50; j < 80; j++) {
			u[i][j] = 1.0;
			v[i][j] = init_param;
		}
	}
	*/
}

void MathFunc::ReactionDiffusion::uvDelete(int x, int y, int range)
{
	int x_min = std::max(x - range, 0);
	int x_max = std::min(x + range, mapsize);
	int y_min = std::max(y - range, 0);
	int y_max = std::min(y + range, mapsize);

	for (int i = x_min; i < x_max; i++) {
		for (int j = y_min; j < y_max; j++) {
			u[i][j] = 0.0f;
			v[i][j] = 0.0f;
		}
	}
}

void MathFunc::ReactionDiffusion::move()
{
	for (int i = 1; i < mapsize - 1; i++) {
		for (int j = 1; j < mapsize - 1; j++) {
			u_next[i][j] = u[i][j] + (ru * ((u[i][j - 1] - 2 * u[i][j] + u[i][j + 1]) + (u[i - 1][j] - 2 * u[i][j] + u[i + 1][j])) - u[i][j] * v[i][j] * v[i][j] + f*(1 - u[i][j]));
			v_next[i][j] = v[i][j] + (rv * ((v[i][j - 1] - 2 * v[i][j] + v[i][j + 1]) + (v[i - 1][j] - 2 * v[i][j] + v[i + 1][j])) + u[i][j] * v[i][j] * v[i][j] - (f + k)*v[i][j]);
		}
	}

	for (int i = 1; i < mapsize - 1; i++) {
		u_next[i][0] = 0;
		u_next[i][mapsize - 1] = 0;
		u_next[0][i] = 0;
		u_next[mapsize - 1][i] = 0;
		v_next[i][0] = 0;
		v_next[i][mapsize - 1] = 0;
		v_next[0][i] = 0;
		v_next[mapsize - 1][i] = 0;
	}

	std::swap(u, u_next);
	std::swap(v, v_next);
}

std::vector <std::vector<float>>& MathFunc::ReactionDiffusion::getU()
{
	return u;
}

std::vector <std::vector<float>>& MathFunc::ReactionDiffusion::getV()
{
	return v;
}