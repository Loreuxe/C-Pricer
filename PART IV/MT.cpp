#include "MT.h"

MT::MT(): generator(std::random_device{}()) {}

double MT::rand_unif()
{
	std::uniform_real_distribution<double>distriunif(0.0, 1.0);
	return distriunif(generator);
}

double MT::rand_norm()
{
	std::normal_distribution<double>distrinorm(0,1.0);
	return distrinorm(generator);
}