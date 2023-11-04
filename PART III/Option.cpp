#include "option.h"

Option::Option(double expiry)
{
    _expiry = expiry;
}
const double Option::GetExpiry(){
    return _expiry;
}

Option::~Option() {}