#include "DigitalOption.h"

OptionNature Option::GetOptionNature() const { return OptionNature::Digital; }


DigitalOption::DigitalOption(double expiry)
{
    _expiry = expiry;
}
const double DigitalOption::GetExpiry() {
    return _expiry;
}

DigitalOption::~DigitalOption() {}