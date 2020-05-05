#ifndef NOISE_H
#define NOISE_H

#include <math.h>
#include <vector>

class Noise1D {
	public:
		Noise1D(const std::vector<float>& values, float depth);

		float get(int x);

		float depth;
	private:
		float getLerpedValue(float x, float degree);
		float lerp(float a, float b, float delta);

		const std::vector<float> values;
};

#endif
