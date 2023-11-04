#pragma once
#include "Option.h"
#include <iostream>
#include <vector>
using namespace std;


enum class OptionType {
    Call,
    Put
};

class AsianOption : public Option {
    private:
        OptionType _optiontype;
        vector<double> _time;
    public:
        AsianOption(vector<double> time, double strike);
        OptionNature GetOptionNature() const override;
        virtual  OptionType GetOptionType() const = 0;
        virtual vector<double> getTimeSteps() const = 0;
        virtual bool isAsianOption() const = 0;
        double payoffPath(vector<double>& past_prices) const ;
};
