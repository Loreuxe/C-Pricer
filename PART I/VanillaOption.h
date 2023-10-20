#pragma once
#include "Option.h"
#include <iostream>
using namespace std;


enum class OptionType {
    Call,
    Put
};

class VanillaOption : public Option{
    using Option::Option;
    private : 
        double _strike;
        OptionType _optiontype;
    public: 
        VanillaOption(double expiry,double strike, OptionType optiontype);
        const OptionType getOptionType();
};
