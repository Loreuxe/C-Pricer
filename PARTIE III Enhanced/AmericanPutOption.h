#pragma once
#include "AmericanOption.h"
using namespace std;

class AmericanPutOption : public AmericanOption {
    public:
        AmericanPutOption(double expiry, double strike);
        OptionType GetOptionType() const override;
        double payoff(double z) const override;
};