#pragma once
#include "VanillaOption.h"
#include <iostream>
using namespace std;

class CallOption : public VanillaOption {
public:
    CallOption(double expiry, double strike);
    OptionType GetOptionType() const override;
    double payoff(double z) const override;
};