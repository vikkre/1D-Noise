#include <iostream>
#include <vector>

#include "noise.h"

const unsigned int depth = 3;
const std::vector<float> rands {0.54f, 0.17f, 0.79f, 0.65f, 0.57f, 0.88f, 0.56f, 0.23f};

int main() {
	Noise1D noise(rands, depth);

	for (float i = 0.0f; i < 100.0f; i += 0.5f) {
		unsigned int height = (unsigned int) (10.0f * noise.get(i) + 63.0f);
		std::cout << height << std::endl;
	}

	return 0;
}
