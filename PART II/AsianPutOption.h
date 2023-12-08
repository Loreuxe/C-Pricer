#ifndef AsianPutOption_H
#define AsianPutOption_H

#include "AsianOption.h"
using namespace std;

class AsianPutOption : public AsianOption {
    public:
        AsianPutOption(double expiry, vector<double> time, double strike);
        OptionType GetOptionType() const override;
        double payoffPath(vector<double>& past_prices) const;

};

#endif