#pragma once
#include <functional>
#include <vector>
#include <algorithm>

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


		//離散関数(スペクトル)の畳み込み(0<=i<=right)
		template <typename T>
		static T conv(const std::vector<T>& f, const std::vector<T>& g) {
			T tmp = (T)0;
			//範囲外の値を参照しても増分は0なので計算しない
			int right;
			right = std::min(f.size(), g.size()) - 1;

			for (int i = 0; i <= right; ++i) {
				tmp += f.at(i) *g.at(right-i);
			}
			return tmp;
		}
	};
}