#pragma once
#include <vector>

namespace MathFunc
{

	class ReactionDiffusion
	{
	private:
		int mapsize;
		float f;
		float k;
		float ru;
		float rv;
		std::vector<std::vector<float>> u;
		std::vector<std::vector<float>> v;
		std::vector<std::vector<float>> u_next;
		std::vector<std::vector<float>> v_next;

		void mapReset();
		void init();

	public:
		ReactionDiffusion(int mapsize);
		ReactionDiffusion(int mapsize,float f,float k,float ru,float rv);

		void uvDelete(int x, int y, int range);
		void move();

		std::vector <std::vector<float>>& getU();
		std::vector <std::vector<float>>& getV();

	};

}
