#ifndef DigitalPutOption_H
#define DigitalPutOption_H
#include "DigitalOption.h"

class DigitalPutOption : public DigitalOption {
    public:
        DigitalPutOption(double expiry, double strike);
        OptionType GetOptionType() const override;
        double payoff(double z) const override;
};


#endif // DigitalPutOption_H