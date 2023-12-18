#include "DigitalOption.h"

OptionNature DigitalOption::GetOptionNature() const { return OptionNature::Digital; }


DigitalOption::DigitalOption(double expiry, double strike) : _expiry(expiry), _strike(strike) {

    if (_strike < 0.0) { throw std::invalid_argument("Strike must be non negative"); }

}

double DigitalOption::GetExpiry() const {
    return _expiry;
}

double DigitalOption::GetStrike() const { return _strike; }