#include "noise.h"

Noise1D::Noise1D(const std::vector<float>& values, unsigned int depth)
:depth(depth), values(values) {
}

float Noise1D::get(float x) {
	float val = 0.0f;
	unsigned int sum = 0;

	for (unsigned int depth = 0; depth < this->depth; ++depth) {
		unsigned int depth_pow = 1 << depth;
		float float_depth_pow = float(depth_pow);

		int x1 = (int(x) / depth_pow    );
		int x2 = (int(x) / depth_pow + 1);
	
		float val1 = this->values.at(x1 % this->values.size());
		float val2 = this->values.at(x2 % this->values.size());

		float delta = (x / float_depth_pow - float(x1)) / float(x2 - x1);

		val += this->lerp(val1, val2, delta) * float_depth_pow;
		sum += depth_pow;
	}

	return val / float(sum);
}

float Noise1D::lerp(float a, float b, float delta) {
	return a + delta * (b - a);
}
