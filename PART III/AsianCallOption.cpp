#include "AsianCallOption.h"
using namespace std;

AsianCallOption::AsianCallOption(vector<double> _time, double _strike) : AsianOption(_time) {}

OptionType AsianCallOption::GetOptionType() const { return OptionType::Call; }

double AsianCallOption::payoff(double z) const {

    if (z >= GetStrike()) { return z - GetStrike(); }
    else { return 0.0; }

}

double AsianCallOption::GetStrike() const { return _strike; }
