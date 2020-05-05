#include <iostream>
#include <vector>

#include "noise.h"

const unsigned int depth = 6;
const std::vector<float> rands {0.54f, 0.17f, 0.79f, 0.65f, 0.57f, 0.88f, 0.56f, 0.23f};

int main() {
	Noise1D noise(rands, depth);

	for (int i = 0; i < 256; ++i) {
		std::cout << noise.get(i) << std::endl;
	}

	return 0;
}
