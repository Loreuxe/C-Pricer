#pragma once
#include "DigitalOption.h"

class DigitalPutOption : public DigitalOption {
    public:
        DigitalPutOption(double expiry, double strike);
        OptionType GetOptionType() const override;
        double payoff(double z) const override;
};
