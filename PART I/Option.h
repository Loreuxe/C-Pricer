#pragma once 
using namespace std;

class Option
{

    public: 
        Option(double expiry);
        const double getExpiry() ;
        virtual double payoff(double price);

    private:
        double _expiry;

};