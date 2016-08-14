#pragma once


namespace MathFunc {
	class InnerProd {

	public:
		template<typename T>
		static T dotProd(const T* a, const T* b) {
			T c = (T)0;
			int arraySize = sizeof(b) / sizeof(b[0]);
			for (int = 0; i < arraySize; ++i) {
				c += a[i] * b[i];
			}
			return c;
		}
	};

}