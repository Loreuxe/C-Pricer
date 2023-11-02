#pragma once 
using namespace std;
#include <vector>

class Option
{

    public: 
        explicit Option(double expiry);
        const double GetExpiry() ;
        virtual double payoff(double price) const = 0;
        virtual bool isAsianOption() const = 0;
        virtual bool isAmericanOption() const = 0;
        double payoffPath(vector<double> past_prices) const;
        

    private:
        double _expiry;

};