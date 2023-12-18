#include "AsianPutOption.h"
using namespace std;

AsianPutOption::AsianPutOption(vector<double> time, double strike) : AsianOption(time), _strike(strike) {
	if (_strike < 0.0) { throw invalid_argument("Strike must be non negative"); }
}

OptionType AsianPutOption::GetOptionType() const { return OptionType::Put; }


double AsianPutOption::payoffPath(vector<double>& past_prices) const {
	double price = 0;
	for (size_t i = 0; i < past_prices.size(); i++) {
		price += past_prices[i];
	}
	if (price / past_prices.size() <= GetStrike()) {
		return GetStrike() - (price / past_prices.size());
	}
	else { return 0.0; }
}

double AsianPutOption::GetStrike() const { return _strike; }

double AsianPutOption::payoff(double z) const {

	return 0.0;

}
