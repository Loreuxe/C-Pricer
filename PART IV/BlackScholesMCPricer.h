#pragma once
#include "vanillaOption.h"
#include <vector>

class  BlackScholesMCPricer
{
public : 
	BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility);
	~BlackScholesMCPricer();
	int GetNbPaths();
	void generate(int nb_paths);
	double operator()();
	std::vector<double>ConfidenceInterval();


private: 
	Option* option_;
	double intial_price;
	double interest_rate;
	double volatility;
	int nb_paths;
	double estimate_price;
};