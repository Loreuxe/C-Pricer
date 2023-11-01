#pragma once
#include "AmericanOption.h"
#include <iostream>
using namespace std;

class AmericanPutOption : public AmericanOption {
    private:
        double _strike;
    public:
        AmericanPutOption(double _strike);
        OptionType GetOptionType() const override;
        double payoff(double z) const override;
        double GetStrike() const;
};