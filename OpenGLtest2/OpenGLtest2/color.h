#pragma once


class Color
{
public:
	static int* rgbTocmy(const int* colors);
	static int* cmyTocmyk(const int* colors);
	static int* cmykTocmy(const int* colors);

};