#include "AsianCallOption.h"
using namespace std;

AsianCallOption::AsianCallOption(vector<double> time, double strike) : AsianOption(time), _strike(strike) {}


OptionType AsianCallOption::GetOptionType() const { return OptionType::Call; }

double AsianCallOption::payoffPath(vector<double>& past_prices) {
	double price = 0;
	for (int i = 0; i < past_prices.size(); i++) {
		price += past_prices[i];
	}
	if (price / past_prices.size() >= GetStrike()) {
		return price / past_prices.size() - GetStrike();
	}
	else { return 0.0; }
}

double AsianCallOption::GetStrike() const { return _strike; }
