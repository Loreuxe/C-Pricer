#include "DigitalOption.h"

OptionNature DigitalOption::GetOptionNature() const { return OptionNature::Digital; }


DigitalOption::DigitalOption(double expiry, double strike) : Option(expiry), _strike(strike) {

    if (_strike < 0.0) { throw std::invalid_argument("Strike must be non negative"); }

}

const double DigitalOption::GetExpiry() {
    return _expiry;
}

double DigitalOption::GetStrike() const { return _strike; }

