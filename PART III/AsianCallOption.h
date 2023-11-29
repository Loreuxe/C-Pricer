#pragma once
#include "AsianOption.h"
using namespace std;

class AsianCallOption : public AsianOption {
    private:
        double _strike;
        vector<double> _time;
    public:
        AsianCallOption(vector<double> time, double strike);
        OptionType GetOptionType() const override;
        double GetStrike() const;
        double payoff(double price) const override;
        double payoffPath(vector<double>& past_prices);
};