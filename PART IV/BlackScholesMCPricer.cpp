#include "BlackScholesMCPricer.h"
#include <cmath>

BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility)
{ }

int BlackScholesMCPricer :: GetNbPaths()
{
	return nb_paths;
}

double BlackScholesMCPricer :: operator()()
{
	if (nb_paths == 0)
	{
	throw std::invalid_argument("Paths must be different to 0");
	}
	else
		return estimate_price / nb_paths;
}
std::vector<double> BlackScholesMCPricer::ConfidenceInterval()
{
	if (nb_paths == 0)
	{
		throw std::invalid_argument("Paths must be different to 0");
	}
	double mean = estimate_price / nb_paths;
	double std = 0;

	for (int i = 0; i < nb_paths; i++)
	{
		double price = intial_price * std::exp((interest_rate * 0.5 * volatility))/* completer la formule */;
		// trouver l'écart type qui se crée 
	}

	double lower_bound = mean - 1.96 * (std / std::sqrt(nb_paths));
	double upper_bound = mean + 1.96 * (std / std::sqrt(nb_paths));

	return { lower_bound, upper_bound };

}

