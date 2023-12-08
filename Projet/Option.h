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
        Option();
        virtual double GetStrike() const = 0;
        virtual double payoff(double price) const = 0;
        virtual  OptionNature GetOptionNature() const = 0;
        virtual  OptionType GetOptionType() const = 0;
        virtual double GetExpiry() const = 0;
        virtual ~Option();
        double payoffPath(std::vector<double> past_prices) const;
        virtual std::vector<double> getTimeSteps() const;

        bool isAsianOption();
        bool isAmericanOption();



    private:
        OptionNature _optionnature;
};