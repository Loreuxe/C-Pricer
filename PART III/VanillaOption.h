#pragma once
#include "Option.h"



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
