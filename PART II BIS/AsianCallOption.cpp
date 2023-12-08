#include "AsianCallOption.h"
using namespace std;

AsianCallOption::AsianCallOption(double expiry, vector<double> time, double strike) : AsianOption(expiry, time, strike) {}


OptionType AsianCallOption::GetOptionType() const { return OptionType::Call; }

double AsianCallOption::payoffPath(vector<double>& past_prices) const {
	double price = 0;
	for (size_t i = 0; i < past_prices.size(); i++) {
		price += past_prices[i];
	}
	if (price / past_prices.size() >= GetStrike()) {
		return price / past_prices.size() - GetStrike();
	}
	else { return 0.0; }
}

