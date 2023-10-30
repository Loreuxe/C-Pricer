#include "CallOption.h"
using namespace std;

CallOption::CallOption(double expiry, double strike) : VanillaOption(expiry,strike){}
OptionType CallOption::GetOptionType() const{ return OptionType::Call;}
double CallOption::payoff(double z) const {
    if(z >= GetStrike() ){return z - GetStrike();}
    else { return 0.0;}

}