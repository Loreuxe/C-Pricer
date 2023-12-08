#include "AsianPutOption.h"
using namespace std;

AsianPutOption::AsianPutOption(double expiry, vector<double> time, double strike) : AsianOption(expiry, time, strike) {}

OptionType AsianPutOption::GetOptionType() const { return OptionType::Put; }


double AsianPutOption::payoffPath(vector<double>& past_prices) const {
	double price = 0;
	for (int i = 0; i < past_prices.size(); i++) {
		price += past_prices[i];
	}
	if (price / past_prices.size() <= GetStrike()) {
		return GetStrike() - price / past_prices.size();
	}
	else { return 0.0; }
}