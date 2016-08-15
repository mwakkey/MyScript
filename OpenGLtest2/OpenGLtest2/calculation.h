#pragma once

	
namespace MathFunc {

	int* sum(const int a[], const int b[]);
	float* sum(const float a[], const float b[]);
	int* sum(const int a[], const int b[], const int c[]);
	float* sum(const float a[], const float b[], const float c[]);

	int* sub(const int a[], const int b[]);
	float* sub(const float a[], const float b[]);

	int* multiply(const int a, const int b[]);
	float* multiply(const float a, const float b[]);
	int* multiply(const int a[], const int b[]);
	float* multiply(const float a[], const float b[]);


}