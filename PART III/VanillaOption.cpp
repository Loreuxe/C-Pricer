#include "VanillaOption.h"
#include "stdexcept"

using namespace std;

OptionNature VanillaOption::GetOptionNature() const { return OptionNature::Vanilla; }


VanillaOption::VanillaOption(double expiry, double strike) : Option(expiry), _strike(strike) {
    
    if(_strike < 0.0){throw invalid_argument("Strike must be non negative");}
    
}
double VanillaOption::GetStrike() const {return _strike;}
