#include "AmericanOption.h"
using namespace std;

AmericanOption::AmericanOption(double expiry, double strike) : Option(expiry), _strike(strike) {

    if (_strike < 0.0) { throw invalid_argument("Strike must be non negative"); }

}

OptionNature AmericanOption::GetOptionNature() const { return OptionNature::American; }

bool AmericanOption::isAmericanOption() {
	if (GetOptionNature() == OptionNature::American) { return true; }
}

double AmericanOption::GetStrike() const { return _strike; }