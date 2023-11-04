#include "AsianCallOption.h"
using namespace std;
#include <vector>

AsianCallOption::AsianCallOption(vector<double> time, double strike) : AsianOption(time, strike) {}

OptionType AsianCallOption::GetOptionType() const { return OptionType::Call; }

double AsianCallOption::payoff(double z) const {

    if (z >= GetStrike()) { return z - GetStrike(); }
    else { return 0.0; }

}

double AsianCallOption::GetStrike() const { return _strike; }
