#pragma once 
using namespace std;

class Option
{

    public: 
        explicit Option(double expiry);
        const double GetExpiry() ;
        virtual double payoff(double price) const = 0;

    private:
        double _expiry;

};