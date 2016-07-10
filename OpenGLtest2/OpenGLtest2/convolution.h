#pragma once
#include <functional>
#include <vector>

namespace MathFunc {
	class Convolution {
	public:
		//連続関数の畳み込み
		template <typename T>
		static T conv(const std::function<T(int)>& f, const std::function<T(int)>& g, int t, int left, int right) {
			T tmp = (T)0;

			for (int i = left; i <=right; ++i) {
				tmp += f(i)*g(t - i);
			}
			return tmp;
		}


		//離散関数(スペクトル)の畳み込み
		template <typename T>
		static T conv(const std::vector<T>& f, const std::vector<T>& g, int t) {
			T tmp = (T)0;

			for (int i = 0; i <= t; ++i) {
				tmp += f.at(i) *g.at(t-i);
			}
			return tmp;
		}
	};
}