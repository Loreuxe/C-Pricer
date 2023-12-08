#ifndef CallOption_H
#define CallOption_H

#include "VanillaOption.h"

class CallOption : public VanillaOption {
public:
    CallOption(double expiry, double strike);
    OptionType GetOptionType() const override;
    double payoff(double z) const override;
};

#endif