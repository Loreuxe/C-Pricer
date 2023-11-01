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
        OptionType _optiontype;
    public:
        virtual  OptionType GetOptionType() const = 0;
        virtual bool isAmericanOption() const = 0;
        virtual ~AmericanOption() {}
};
