#pragma once
#include "Option.h"
#include <iostream>
using namespace std;


enum class OptionType {
    Call,
    Put
};

class AmericanOption : public Option {
    private:
        double _strike;
        OptionType _optiontype;
    public:
        AmericanOption(double expiry, double strike);
        virtual  OptionType GetOptionType() const = 0;
        OptionNature GetOptionNature() const override;
        virtual bool isAmericanOption() const = 0;
        double GetStrike() const;
};
