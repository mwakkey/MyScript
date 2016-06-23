#pragma once
#include <cstdint>

namespace MathFunc{

	unsigned long seed1;
	unsigned long seed2;
	
	void xorShift(const unsigned long s1, const unsigned long s2)
	{
		seed1 = s1;
		seed2 = s2;
	}

	//[min,max)
	unsigned long rand(const unsigned long min, const unsigned long max)
	{
		unsigned long tmp1 = seed1;
		unsigned long tmp2 = seed2;
		seed1 = tmp2; //update seed1

		tmp1 ^= tmp1 << 23;
		tmp1 = (tmp1 ^ (tmp1 >> 18)) ^ (tmp2 ^ (tmp2 >> 5));
		seed2 = tmp1; //update seed2

		return (min + ((tmp1 + tmp2) % (max - min)));
	}
	
}