#ifndef AmericanCallOption_H
#define AmericanCallOption_H
#include "AmericanOption.h"
using namespace std;

class AmericanCallOption : public AmericanOption {
    public:
        AmericanCallOption(double expiry, double strike);
        OptionType GetOptionType() const override;
        double payoff(double z) const override;

};

#endif // AmericanCallOption_H