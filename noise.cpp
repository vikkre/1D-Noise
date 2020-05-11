#include "noise.h"

Noise1D::Noise1D(const std::vector<float>& values, unsigned int depth)
:depth(depth), values(values) {
}

float Noise1D::get(float x) {
	float val = 0.0f;
	float sum = 0;

	for (unsigned int depth = 0; depth < this->depth; ++depth) {
		float degree = pow(2.0f, float(depth));

		val += this->getLerpedValue(x, degree) * degree;
		sum += int(degree);
	}

	return val / float(sum);
}

float Noise1D::getLerpedValue(float x, float degree) {
	int x1 = (int(x) / int(degree)    );
	int x2 = (int(x) / int(degree) + 1);
 
	float val1 = this->values.at(x1 % this->values.size());
	float val2 = this->values.at(x2 % this->values.size());

	float delta = (x / degree - float(x1)) / float(x2 - x1);

	return this->lerp(val1, val2, delta);
}

float Noise1D::lerp(float a, float b, float delta) {
  return a + delta * (b - a);
}
