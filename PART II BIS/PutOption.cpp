#include "PutOption.h"

PutOption::PutOption(double expiry, double strike) : VanillaOption(expiry, strike){}
OptionType PutOption::GetOptionType() const{return OptionType::Put;}
double PutOption::payoff(double z) const {
    if (z >= GetStrike()){return GetStrike() - z;}
    else{return 0.0;}
}
