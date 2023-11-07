#pragma once
#include "Option.h"
using namespace std;



class AmericanOption : public Option {
    private:
        double _strike;
        OptionType _optiontype;
        OptionNature American;
    public:
        AmericanOption(double expiry, double strike);
        virtual  OptionType GetOptionType() const = 0;
        OptionNature GetOptionNature() const override;
        bool isAmericanOption();
        double GetStrike() const;
};