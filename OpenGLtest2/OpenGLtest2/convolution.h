#pragma once
#include <functional>
#include <vector>
#include <algorithm>

namespace MathFunc {
	class Convolution {
	public:
		//�A���֐��̏�ݍ���
		template <typename T>
		static T conv(const std::function<T(int)>& f, const std::function<T(int)>& g, int t, int left, int right) {
			T tmp = (T)0;

			for (int i = left; i <=right; ++i) {
				tmp += f(i)*g(t - i);
			}
			return tmp;
		}


		//���U�֐�(�X�y�N�g��)�̏�ݍ���(0<=i<=right)
		template <typename T>
		static T conv(const std::vector<T>& f, const std::vector<T>& g) {
			T tmp = (T)0;
			//�͈͊O�̒l���Q�Ƃ��Ă�������0�Ȃ̂Ōv�Z���Ȃ�
			int right;
			right = std::min(f.size(), g.size()) - 1;

			for (int i = 0; i <= right; ++i) {
				tmp += f.at(i) *g.at(right-i);
			}
			return tmp;
		}
	};
}