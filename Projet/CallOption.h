#pragma once
#include "VanillaOption.h"

class CallOption : public VanillaOption {
public:
    CallOption(double expiry, double strike);
    OptionType GetOptionType() const override;
    double payoff(double z) const override;

};