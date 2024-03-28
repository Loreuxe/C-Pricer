#ifndef PutOption_H
#define PutOption_H
#include "VanillaOption.h"

class PutOption : public VanillaOption {
public:
    PutOption(double expiry, double strike);
    OptionType GetOptionType() const override;
    double payoff(double z) const override;
};
#endif // PutOption_H