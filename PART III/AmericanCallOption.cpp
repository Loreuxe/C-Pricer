#include "AmericanCallOption.h"
using namespace std;

AmericanCallOption::AmericanCallOption(double _strike) : _strike(strike) {}

OptionType AmericanCallOption::GetOptionType() const { return OptionType::Call; }

double AmericanCallOption::payoff(double z) const {

    if (z >= GetStrike()) { return z - GetStrike(); }
    else { return 0.0; }

}

double AmericanCallOption::GetStrike() const { return _strike; }
