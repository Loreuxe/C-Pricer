#ifndef VanillaOption_H
#define VanillaOption_H
#include "Option.h"


class VanillaOption : public Option{
    private : 
        double _expiry;
        double _strike;
        OptionType _optiontype;
    public:
        double GetExpiry() const override;
        VanillaOption(double expiry, double strike);
        virtual OptionType GetOptionType() const = 0;
        OptionNature GetOptionNature() const override;
        double GetStrike() const;
};


#endif // VanillaOption_H