#include "option.h"

Option::Option(double expiry)
{
    _expiry = expiry;
}
const double Option::GetExpiry(){
    return _expiry;
}

VanillaOption::VanillaOption(double expiry, double strike) : Option(expiry), _strike(strike) {

    if (_strike < 0.0) { throw ("Strike must be non negative"); }

}
double VanillaOption::GetStrike() const { return _strike; }
Option::~Option() {}

VanillaCallOption::VanillaCallOption(double expiry, double strike) : VanillaOption(expiry, strike) {}
OptionType VanillaCallOption::GetOptionType() const { return OptionType::Call; }
double VanillaCallOption::payoff(double z) const {
    if (z >= GetStrike()) { return z - GetStrike(); }
    else { return 0.0; }

}
VanillaPutOption::VanillaPutOption(double expiry, double strike) : VanillaOption(expiry, strike) {}
OptionType VanillaPutOption::GetOptionType() const { return OptionType::Put; }
double VanillaPutOption::payoff(double z) const {
    if (z >= GetStrike()) { return GetStrike() - z; }
    else { return 0.0; }
}
using namespace std;

DigitalOption::DigitalOption(double expiry, double strike) : Option(expiry), _strike(strike) {}

double DigitalOption::GetStrike() const {
    return _strike;
}
DigitalCallOption::DigitalCallOption(double expiry, double strike) : DigitalOption(expiry, strike) {}

double DigitalCallOption::payoff(double z) const {
    return (z >= GetStrike()) ? 1.0 : 0.0;
}
DigitalPutOption::DigitalPutOption(double expiry, double strike) : DigitalOption(expiry, strike) {}

double DigitalPutOption::payoff(double z) const {
    return (z <= GetStrike()) ? 1.0 : 0.0;
}