#include "AsianPutOption.h"
using namespace std;

AsianPutOption::AsianPutOption(vector<double> time, double strike) : AsianOption(time, strike) {}

OptionType AsianPutOption::GetOptionType() const { return OptionType::Put; }

double AsianPutOption::payoff(double z) const {

    if (z <= GetStrike()) { return GetStrike() - z; }
    else { return 0.0; }

}
