#include "option.h"
#include <iostream>

using namespace std;


Option::Option(double expiry)
{
    _expiry = expiry;
}
const double Option::getExpiry(){
    return _expiry;
}

double Option::payoffPath(vector<double> past_prices) const { return payoff(past_prices[0]); }

bool isAsianOption() { return false; }

bool isAmericanOption() { return false; }