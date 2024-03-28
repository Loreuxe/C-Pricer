#ifndef AmericanPutOption_H
#define AmericanPutOption_H
#include "AmericanOption.h"
using namespace std;

class AmericanPutOption : public AmericanOption {
    public:
        AmericanPutOption(double expiry, double strike);
        OptionType GetOptionType() const override;
        double payoff(double z) const override;
};

#endif // AmericanPutOption_H