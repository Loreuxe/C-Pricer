#ifndef AsianCallOption_H
#define AsianCallOption_H

#include "AsianOption.h"
using namespace std;

class AsianCallOption : public AsianOption {
    private:
        double _strike;
    public:
        AsianCallOption(double expiry, vector<double> time, double strike);
        OptionType GetOptionType() const override;
        double payoffPath(vector<double>& past_prices) const;
};

#endif // Asian_Call_Option