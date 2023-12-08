#ifndef AsianOption_H
#define AsianOption_H

#include "Option.h"
using namespace std;


class AsianOption : public Option {
    private:
        
        OptionType _optiontype;
        vector<double> _time;
        double _strike;
    public:
        AsianOption(double expiry, vector<double> time, double strike);
        OptionNature GetOptionNature() const override;
        double GetStrike() const;
        virtual  OptionType GetOptionType() const = 0;
        virtual vector<double> getTimeSteps() const = 0;
        bool isAsianOption();
        double payoffPath(vector<double>& past_prices) const ;
};

#endif // Asian_Option