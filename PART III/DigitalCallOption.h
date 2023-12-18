#ifndef DigitalCallOption_H
#define DigitalCallOption_H
#include "DigitalOption.h"

class DigitalCallOption : public DigitalOption {
    public:
        DigitalCallOption(double expiry, double strike);
        OptionType GetOptionType() const override;
        double payoff(double z) const override;
};

#endif // DigitalCallOption_H