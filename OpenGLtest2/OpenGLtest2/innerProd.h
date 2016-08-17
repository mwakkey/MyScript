#pragma once


namespace MathFunc {
	class InnerProd {

	public:
		static int dotProd(const int* a, const int* b) {
			int c = 0;
			int arraySize = sizeof(b) / sizeof(b[0]);
			for (int i = 0; i < arraySize; ++i) {
				c += a[i] * b[i];
			}
			return c;
		}
		static float dotProd(const float* a, const float* b) {
			float c = 0.0f;
			int arraySize = sizeof(b) / sizeof(b[0]);
			for (int i = 0; i < arraySize; ++i) {
				c += a[i] * b[i];
			}
			return c;
		}
		static double dotProd(const double* a, const double* b) {
			double c = 0.0;
			int arraySize = sizeof(b) / sizeof(b[0]);
			for (int i = 0; i < arraySize; ++i) {
				c += a[i] * b[i];
			}
			return c;
		}
	};

}