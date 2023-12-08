#pragma once
#include "Option.h"
using namespace std;




class AsianOption : public Option {
    private:
        double _strike;
        OptionType _optiontype;
        vector<double> _time;
    public:
        AsianOption(double expiry, vector<double> time, double strike);
        OptionNature GetOptionNature() const override;
        double GetStrike() const;
        virtual  OptionType GetOptionType() const = 0;
        virtual vector<double> getTimeSteps() const = 0;
        bool isAsianOption();
        double payoffPath(vector<double>& past_prices) const ;
};
