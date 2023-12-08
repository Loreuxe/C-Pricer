#pragma once 
#include <vector>
#include <iostream>
#include "stdexcept"



enum class OptionNature {
    American,
    Asian,
    Digital,
    Vanilla

};

enum class OptionType {
    Call,
    Put
};

class Option
{

    public: 
        explicit Option(double expiry);
        const double GetExpiry() ;
        virtual double GetStrike() const = 0;
        virtual double payoff(double price) const = 0;
        virtual  OptionNature GetOptionNature() const = 0;
        virtual  OptionType GetOptionType() const = 0;
        virtual ~Option();
        double payoffPath(std::vector<double> past_prices);
        bool isAsianOption();
        bool isAmericanOption();



    private:
        double _expiry;
        OptionNature _optionnature;
};