#ifndef AsianCallOption_H
#define AsianCallOption_H
#include "AsianOption.h"
using namespace std;

class AsianCallOption : public AsianOption {
    private:
        double _strike;
        vector<double> _time;
    public:
        AsianCallOption(vector<double> time, double strike);
        OptionType GetOptionType() const override;

        double GetStrike() const override;
        double payoff(double price) const;
        double payoffPath(vector<double> past_prices) const;
};

#endif // AsianCallOption_H