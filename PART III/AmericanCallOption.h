#pragma once
#include "AmericanOption.h"
#include <iostream>
using namespace std;

class AmericanCallOption : public AmericanOption {
    public:
        AmericanCallOption(double expiry, double strike);
        OptionType GetOptionType() const override;
        double payoff(double z) const override;

};