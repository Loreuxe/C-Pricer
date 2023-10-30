#include "BlackScholesPricer.h"
#include <cmath>
#include "stdexcept"

BlackScholesPricer::BlackScholesPricer(VanillaOption* option, double asset_price, double interest_rate, double volatility) : option_(option), asset_price_(asset_price), interest_rate_(interest_rate), volatility_(volatility){
    if(option_ == nullptr){throw invalid_argument("Option must be initialize as it's a pointer");}
}
double BlackScholesPricer::operator()() const{
    double S = asset_price_;
    double K = option_ -> GetStrike();
    double T = option_ -> GetExpiry();
    
}
