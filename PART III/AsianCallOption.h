#pragma once
#include "AsianOption.h"
#include <iostream>
#include <vector>
using namespace std;

class AsianCallOption : public AsianOption {
    private:
        double _strike;
    public:
        AsianCallOption(vector<double> time, double strike);
        OptionType GetOptionType() const override;
        double payoff(double z) const override;
        double GetStrike() const;
};