#pragma once
#include "DigitalOption.h"

class DigitalCallOption : public DigitalOption {
    public:
        DigitalCallOption(double expiry, double strike);
        OptionType GetOptionType() const override;
        double payoff(double z) const override;
};