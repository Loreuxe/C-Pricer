#include "VanillaOption.h"
using namespace std;

OptionNature VanillaOption::GetOptionNature() const { return OptionNature::Vanilla; }

double VanillaOption::GetExpiry() const {
    return _expiry;
}


VanillaOption::VanillaOption(double expiry, double strike) : _expiry(expiry), _strike(strike) {
    
    if(_strike < 0.0){throw invalid_argument("Strike must be non negative");}
    
}
double VanillaOption::GetStrike() const {return _strike;}
