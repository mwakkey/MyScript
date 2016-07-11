#pragma once
#include <vector>
#include <iostream>

namespace MathFunc
{

	class CrossProd
	{
	public:
		template <typename T>
		static T* cross3D(const T* vec1, const T* vec2)
		{
			T ret[3];
			ret[0] = (vec1[1] * vec2[2] - vec1[2] * vec2[1]);
			ret[1] = (vec1[2] * vec2[0] - vec1[0] * vec2[2]);
			ret[2] = (vec1[0] * vec2[1] - vec1[1] * vec2[0]);
			return ret;
		}

	};
}