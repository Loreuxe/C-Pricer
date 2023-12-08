#include "Option.h"

Option::Option(double expiry)
{
    _expiry = expiry;
}
const double Option::GetExpiry(){
    return _expiry;
}

bool Option::isAmericanOption() { return false; }

bool Option::isAsianOption() { return false; }


Option::~Option() {}