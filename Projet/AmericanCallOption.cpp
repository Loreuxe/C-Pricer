#include "AmericanCallOption.h"
using namespace std;

AmericanCallOption::AmericanCallOption(double expiry, double strike) : AmericanOption(expiry, strike) {}

OptionType AmericanCallOption::GetOptionType() const { return OptionType::Call; }

double AmericanCallOption::payoff(double z) const {

    if (z >= GetStrike()) { return z - GetStrike(); }
    else { return 0.0; }

}

