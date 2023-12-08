#include "DigitalPutOption.h"

DigitalPutOption::DigitalPutOption(double expiry, double strike) : DigitalOption(expiry, strike) {}

OptionType DigitalPutOption::GetOptionType() const { return OptionType::Put; }

double DigitalPutOption::payoff(double z) const {
    if (z <= GetStrike()) { return 1.0; }
    else { return 0.0; }

}