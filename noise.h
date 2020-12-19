#ifndef NOISE_H
#define NOISE_H

#include <vector>


class Noise1D {
	public:
		Noise1D(const std::vector<float>& values, unsigned int depth);

		float get(float x);

		unsigned int depth;
	private:
		float lerp(float a, float b, float delta);

		const std::vector<float> values;
};

#endif
