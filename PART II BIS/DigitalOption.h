#ifndef DigitalOption_H
#define DigitalOption_H
#include "Option.h"



class DigitalOption : public Option{
    public:
        explicit DigitalOption(double expiry, double strike);
        const double GetExpiry();
        double GetStrike() const;
        virtual double payoff(double price) const = 0;
        virtual  OptionType GetOptionType() const = 0;
        OptionNature GetOptionNature() const override;

    private:
        double _expiry;
        double _strike;
        OptionType _optiontype;

};
#endif