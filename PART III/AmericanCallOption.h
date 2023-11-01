#pragma once
#include "AmericanOption.h"
#include <iostream>
using namespace std;

class AmericanCallOption : public AmericanOption {
    private:
        double _strike;
    public:
        AmericanCallOption(double strike);
        OptionType GetOptionType() const override;
        double payoff(double z) const override;
        double GetStrike() const;
};