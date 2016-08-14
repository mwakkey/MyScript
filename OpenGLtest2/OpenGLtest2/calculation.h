#pragma once

	
namespace MathFunc {
	template<typename T>
	T* sum(const T* a, const T* b) {
		T c[];
		int arraySize = sizeof(b) / sizeof(b[0]);
		for (int i = 0; i < arraySize; ++i) {
			c[i] = a[i] + b[i];
		}
		return c;
	}
	template<typename T>
	T* sum(const T* a, const T* b,const T*c) {
		T d[];
		int arraySize = sizeof(b) / sizeof(b[0]);
		for (int i = 0; i < arraySize; ++i) {
			d[i] = a[i] + b[i] + c[i];
		}
		return d;
	}

	template<typename T>
	T* sub(const T* a, const T* b) {
		T c[];
		int arraySize = sizeof(b) / sizeof(b[0]);
		for (int i = 0; i < arraySize; ++i) {
			c[i] = a[i] - b[i];
		}
		return c;
	}

	template<typename T>
	T* multiply(const T a, const T* b) {
		T c[];
		int arraySize = sizeof(b) / sizeof(b[0]);
		for (int i = 0; i < arraySize; ++i) {
			c[i] = a*b[i];
		}

		return c;
	}

	template<typename T>
	T* multiply(const T* a, const T* b[]) {
		T c[];
		int arraySize = sizeof(b) / sizeof(b[0]);
		for (int i = 0; i < arraySize; ++i) {
			c[i] = a[i] * b[i];
		}
		return c;
	}
}