#include "VanillaOption.h"


class BlackScholesPricer{
    
    public:
    friend class VanillaOption;
    BlackScholesPricer(VanillaOption* option, double asset_price, double interest_rate, double volatility);
    double operator()() const;
    double delta() const;

    private: 
    VanillaOption* option_;
    double asset_price_;
    double interest_rate_;
    double volatility_;

};