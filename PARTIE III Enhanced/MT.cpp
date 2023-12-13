#include "MT.h"

MT::MT() : generator(std::random_device{}()) {}

MT::~MT() {}

MT& MT::seed() {
	static MT seed;
	return seed;
}

double MT::rand_unif() {
	std::uniform_real_distribution<double> distribution(0.0, 1.0);
	return distribution(seed().generator);

}

double  MT::rand_norm() {
	std::normal_distribution<double> distribution(0.0, 1.0);
	return distribution(seed().generator);
}