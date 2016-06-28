#pragma once


namespace MathFunc{
	class XorShift
	{
	private:
		static unsigned long seed1;
		static unsigned long seed2;

	public:
		static void xorShift(const unsigned long s1, const unsigned long s2);

		//[min,max)
		static unsigned long rand(const unsigned long min, const unsigned long max);
	};
}