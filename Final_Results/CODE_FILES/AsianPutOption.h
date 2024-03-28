#ifndef AsianPutOption_H
#define AsianPutOption_H
#include "AsianOption.h"
using namespace std;

class AsianPutOption : public AsianOption {
    private:
        double _strike;
        vector<double> _time;
    public:
        AsianPutOption(vector<double> time, double strike);
        OptionType GetOptionType() const override;
        double GetStrike() const override;
        double payoff(double price) const;
        double payoffPath(vector<double>& past_prices) const;

};

#endif // AsianPutOption_H