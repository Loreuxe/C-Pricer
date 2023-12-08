#include "AmericanOption.h"
#include "AsianOption.h"
#include "VanillaOption.h"
#include "MT.h"




class BlackScholesMCPricer {

public:
    friend class Option;
    friend class AmericanOption;
    friend class AsianOption;
    friend class VanillaOption;
    BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility);
    double operator()() const;
    
    int getNbPaths() const;
    void generate(int nb_paths);
    vector<double> confidenceInterval();
    

private:
    Option* option_;
    double initial_price_;
    double interest_rate_;
    double volatility_;
    int NbPaths = 0;
    vector<double> prices;
    double current_estimate  = 0;
    
};