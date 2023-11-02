#pragma once 

enum class OptionNature {
    American,
    Asian,
    Digital,
    Vanilla

};

class Option
{

    public: 
        explicit Option(double expiry);
        const double GetExpiry() ;
        virtual double payoff(double price) const = 0;
        virtual  OptionNature GetOptionNature() const = 0;
        virtual ~Option();
    private:
        double _expiry;
        OptionNature _optionnature;
};