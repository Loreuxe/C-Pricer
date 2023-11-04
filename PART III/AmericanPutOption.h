#pragma once
#include "AmericanOption.h"
#include <iostream>
using namespace std;

class AmericanPutOption : public AmericanOption {
    public:
        AmericanPutOption(double expiry, double strike);
        OptionType GetOptionType() const override;
        double payoff(double z) const override;
        double GetStrike() const;
};