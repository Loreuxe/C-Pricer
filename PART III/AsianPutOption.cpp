#include "AsianPutOption.h"
using namespace std;

AsianPutOption::AsianPutOption(vector<double> time, double strike) : AsianOption(time) _strike(strike) {}

OptionType AsianPutlOption::GetOptionType() const { return OptionType::Put; }

double AsianPutOption::payoff(double z) const {

    if (z <= GetStrike()) { return GetStrike() - z; }
    else { return 0.0; }

}

double AsianPutOption::GetStrike() const { return _strike; }
