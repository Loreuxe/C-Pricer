#pragma once
#include "Option.h"
#include <iostream>



enum class OptionType {
    Call,
    Put
};

class VanillaOption : public Option{
    private : 
        double _strike;
        OptionType _optiontype;
    public:
        VanillaOption(double expiry, double strike);
        virtual  OptionType GetOptionType() const = 0;
        OptionNature GetOptionNature() const override;
        double GetStrike() const;
};
