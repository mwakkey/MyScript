#pragma once
#include <functional>

namespace MathFunc
{

	class Derivative
	{
	public:
		template <typename T>
		static T derivative(std::function<T(T x)>& f, T coef, float delta)
		{
			return (f(coef + delta) - f(coef)) / delta;
		}

		template <typename T>
		static T derivative(std::function<T(T x, T y)>& f, T coef1, T coef2, float delta, int n)
		{
			if (n == 1) {
				return (f(coef1 + delta, coef2) - f(coef1, coef2)) / delta;
			}
			if (n == 2) {
				return (f(coef1, coef2 + delta) - f(coef1, coef2)) / delta;
			}
		}
	};
}