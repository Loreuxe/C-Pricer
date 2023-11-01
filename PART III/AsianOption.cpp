#include "AsianOption.h"
#include "stdexcept"

using namespace std;


vector<double> AsianOption::getTimeSteps() const { return _time; }

double AsianOption::payoffPath(vector<double> past_prices) const {
	double price = 0;
	for (int i = 0; i < past_prices.size(); i++) {
		price += past_prices[i];
	}
	return Option::payoff(price / past_prices.size());
}

bool AsianOption::isAsianOption() const { return true; }