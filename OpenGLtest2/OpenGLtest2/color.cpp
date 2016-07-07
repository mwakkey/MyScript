
#include <algorithm>
#include "color.h"

int* Color::rgbTocmy(int* colors)
{
	int tmpColors[3];
	for (int i = 0; i < 3;++i) {
		tmpColors[i] = 255 - colors[i];
	}

	return tmpColors;
}

int* Color::cmyTocmyk(int* colors)
{
	int tmpColors[4];
	tmpColors[3] = *std::min_element(colors, colors+3);

	for (int i = 0; i < 3; ++i) {
		tmpColors[i] = colors[i] - tmpColors[3];
	}

	return tmpColors;
}

int* Color::cmykTocmy(int* colors)
{
	int tmpColors[3];
	for (int i = 0; i < 3; ++i) {
		tmpColors[i] = colors[i] + colors[3];
	}

	return tmpColors;
}
