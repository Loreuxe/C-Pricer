#include "BlackScholesMCPricer.h"
#include <cmath>


BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility) : 
	option_(option), initial_price_(initial_price), interest_rate_(interest_rate), volatility_(volatility)
{
	if (option_ == nullptr) { throw invalid_argument("Option must be initialize as it's a pointer"); }
}

int BlackScholesMCPricer::getNbPaths() const {
	return NbPaths;
}

double BlackScholesMCPricer :: operator()() const
{
	if (NbPaths == 0)
	{
	throw std::invalid_argument("Paths must be different to 0");
	}
	else
		return estimate_price / NbPaths;
}

vector<double> BlackScholesMCPricer::generate(int nb_paths = 1) const {
	double S = initial_price_;
	double K = option_->GetStrike();
	double T = option_->GetExpiry();
	double r = interest_rate_;
	double sigma = volatility_;
	vector<double> t;
	vector<double> prices = { S };

	NbPaths += nb_paths;

	for (int i = 0; i < nb_paths; i++) {
		t.push_back(i);
	}

	if (option_->GetOptionNature() == OptionNature::Vanilla) {
		double z = MT::rand_norm();
		double s = prices[0] * exp((r - 0.5 * pow(sigma, 2)) * 1 + sigma * sqrt(1) * z);

		prices.push_back(s);
		return prices;
	}
	double current_estimate = 0;
	vector <double> premium;

	if (option_->GetOptionNature() == OptionNature::Vanilla)
	{
		if (option_->GetOptionType() == OptionType::Call)
		{

		}
	}
	/*else if (option_->GetOptionNature() == OptionNature::Asian) {
		vector<double> time = AsianOption::getTimeSteps();
		for (int j = 1; j < nb_paths; j++) {
			double z = MT::rand_norm();
			double s = prices[j - 1] * exp((r - 0.5 * pow(sigma, 2)) * (t[j] - t[j - 1]) + sigma * sqrt(t[j] - t[j - 1]) * z);
			prices.push_back(s);
		}
		return prices;
	} */

}

std::vector<double> BlackScholesMCPricer::confidenceInterval()
{
	
	if (NbPaths == 0)
	{
		throw std::invalid_argument("Paths must be different to 0");
	}
	double mean = estimate_price / NbPaths;
	double std = 0;
	
	// calcul des rendements 
	list <double> rendement;
	for (int i = 1; i < NbPaths; i++)

	{ rendement = (price(i) - price(i - 1)) / price(i - 1);	}
	
	
	double ecart_carres = 0;
	for (int i = 0; i < rendement.size(); i++)
	{
		int a = 0;

		a = a + i;

		double moyenne = a / rendement.size();

		double ecart_carres = 0;

		ecart_carres = (moyenne - i) * (moyenne - i);

	}
	double ecartype = std::sqrt(ecart_carres / rendement.size() - 1);
	

	double lower_bound = mean - 1.96 * (ecartype / std::sqrt(NbPaths));
	double upper_bound = mean + 1.96 * (ecartype / std::sqrt(NbPaths));

	return { lower_bound, upper_bound };

}

