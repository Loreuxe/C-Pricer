#pragma once
#include "Option.h"
using namespace std;




class AsianOption : public Option {
    private:
        OptionType _optiontype;
        vector<double> _time;
    public:
        AsianOption(vector<double> time);
        OptionNature GetOptionNature() const override;
        virtual  OptionType GetOptionType() const = 0;
        vector<double> getTimeSteps();
        double GetStrike() const;
        bool isAsianOption();
        double payoffPath(vector<double>& past_prices) const;

};
