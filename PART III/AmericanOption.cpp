#include "AmericanOption.h"
#include "stdexcept"

using namespace std;

OptionNature Option::GetOptionNature() const { return OptionNature::American; }

bool AmericanOption::isAmericanOption() const { return true; }

