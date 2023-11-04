#pragma once
#include "AsianOption.h"
#include <iostream>
using namespace std;

class AsianPutOption : public AsianOption {
    public:
        AsianPutOption(vector<double> time, double strike);
        OptionType GetOptionType() const override;
        double payoff(double z) const override;
        double GetStrike() const;
};