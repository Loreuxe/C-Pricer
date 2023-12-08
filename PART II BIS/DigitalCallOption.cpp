#include "DigitalCallOption.h"

DigitalCallOption::DigitalCallOption(double expiry, double strike) : DigitalOption(expiry, strike) {}

OptionType DigitalCallOption::GetOptionType() const { return OptionType::Call; }

double DigitalCallOption::payoff(double z) const {
    if (z >= GetStrike()) { return 1.0; }
    else { return 0.0; }
}