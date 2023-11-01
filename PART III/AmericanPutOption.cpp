*#include "AmericanPutOption.h"
using namespace std;

AmericanPutOption::AmericanPutOption(double _strike) : _strike(strike) {}

OptionType AmericanPutOption::GetOptionType() const { return OptionType::Put; }

double AmericanPutOption::payoff(double z) const {

    if (z <= GetStrike()) { return GetStrike() - z; }
    else { return 0.0; }

}

double AmericanPutOption::GetStrike() const { return _strike; }
