#include "calculation.h"



int* MathFunc::sum(const int a[], const int b[]) {
	const int arraySize = sizeof(b) / sizeof(b[0]);
	int c[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		c[i] = a[i] + b[i];
	}
	return c;
}
float* MathFunc::sum(const float a[], const float b[]) {
	const int arraySize = sizeof(b) / sizeof(b[0]);
	float c[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		c[i] = a[i] + b[i];
	}
	return c;
}

int* MathFunc::sum(const int a[], const int b[], const int c[]) {
	const int arraySize = sizeof(b) / sizeof(b[0]);
	int d[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		d[i] = a[i] + b[i] + c[i];
	}
	return d;
}
float* MathFunc::sum(const float a[], const float b[], const float c[]) {
	const int arraySize = sizeof(b) / sizeof(b[0]);
	float d[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		d[i] = a[i] + b[i] + c[i];
	}
	return d;
}


int* MathFunc::sub(const int a[], const int b[]) {
	const int arraySize = sizeof(b) / sizeof(b[0]);
	int c[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		c[i] = a[i] - b[i];
	}
	return c;
}
float* MathFunc::sub(const float a[], const float b[]) {
	const int arraySize = sizeof(b) / sizeof(b[0]);
	float c[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		c[i] = a[i] - b[i];
	}
	return c;
}


int* MathFunc::multiply(const int a, const int b[]) {
	const int arraySize = sizeof(b) / sizeof(b[0]);
	int c[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		c[i] = a*b[i];
	}

	return c;
}
float* MathFunc::multiply(const float a, const float b[]) {
	const int arraySize = sizeof(b) / sizeof(b[0]);
	float c[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		c[i] = a*b[i];
	}

	return c;
}


int* MathFunc::multiply(const int a[], const int b[]) {
	const int arraySize = sizeof(b) / sizeof(b[0]);
	int c[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		c[i] = a[i] * b[i];
	}
	return c;
}
float* MathFunc::multiply(const float a[], const float b[]) {
	const int arraySize = sizeof(b) / sizeof(b[0]);
	float c[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		c[i] = a[i] * b[i];
	}
	return c;
}
