#include "option.h"
#include <iostream>

using namespace std;


Option::Option(double expiry)
{
    _expiry = expiry;
}
const double Option::getExpiry(){
    return _expiry;
}
double Option::payoff(double price){}