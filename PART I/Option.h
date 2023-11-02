#pragma once 

class Option
{

    public: 
        explicit Option(double expiry);
        const double GetExpiry() ;
        virtual double payoff(double price) const = 0;
        virtual ~Option();
    private:
        double _expiry;

};