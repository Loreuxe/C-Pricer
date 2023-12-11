#include "VanillaOption.h"
#include "DigitalOption.h"



class BlackScholesPricer{
    
    public:
        friend class DigitalOption;
        friend class VanillaOption;
        friend class Option;
        BlackScholesPricer(Option* option, double asset_price, double interest_rate, double volatility);
        ~BlackScholesPricer();
        double operator()() const;
        double delta() const;

    private: 
        Option* option_;
        double asset_price_;
        double interest_rate_;
        double volatility_;

};