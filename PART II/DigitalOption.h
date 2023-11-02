#pragma once 
#include "Option.h"

enum class OptionType {
    Call,
    Put
};

class DigitalOption : public Option{
    public:
        explicit DigitalOption(double expiry);
        const double GetExpiry();
        virtual double payoff(double price) const = 0;
        virtual ~DigitalOption();
        OptionNature GetOptionNature() const override;
    private:
        double _expiry;

};