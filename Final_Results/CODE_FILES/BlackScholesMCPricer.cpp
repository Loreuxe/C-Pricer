#include "BlackScholesMCPricer.h"
#include "BlackScholesPricer.h"
#include <cmath>
#include "stdexcept"
using namespace std;


BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility) : option_(option), initial_price_(initial_price), interest_rate_(interest_rate), volatility_(volatility) {}


void BlackScholesMCPricer::generate(int nb_paths = 1) {
    double S = initial_price_;
    // double K = option_ -> GetStrike(); Ligne inutile car on regarde NbPath pour le prix de l'option 
    double T = option_ -> GetExpiry();
    double r = interest_rate_;
    double sigma = volatility_;
    vector<vector<double>> sim_prices;
    

    NbPaths += nb_paths;

    for (int k = 0; k < nb_paths; k++) {

        if (option_->GetOptionNature() == OptionNature::Vanilla || option_->GetOptionNature() == OptionNature::Digital) {
            double z = MT::rand_norm();
            double s = S * exp((r - 0.5 * pow(sigma, 2)) * T + sigma * sqrt(T) * z);
            sim_prices.push_back(vector<double> {s});

        }

        else {
            double z = MT::rand_norm();
            vector<double> t = option_->getTimeSteps();
            vector<double> prices = { S * exp((r - 0.5 * pow(sigma, 2)) * t[0] + sigma * sqrt(t[0]) * z) };
            for (size_t j = 1; j < t.size(); j++) {
                double z = MT::rand_norm();
                double s = prices[j - 1] * exp((r - 0.5 * pow(sigma, 2)) * (t[j] - t[j - 1]) + sigma * sqrt(t[j] - t[j - 1]) * z);
                prices.push_back(s);
            }
            sim_prices.push_back(prices);
        }
    }
    

    if (option_->GetOptionNature() == OptionNature::Asian) {
        for (int k = 0; k < nb_paths; k++) {
            sum_payoff += option_->payoffPath(sim_prices[k]);
            squared_payoff += pow(option_->payoffPath(sim_prices[k]), 2);
        }
        
        vector<double> t = option_->getTimeSteps();
        current_estimate = exp(-r * t[t.size() - 1]) * sum_payoff / NbPaths;
    }

    else {
        for (int k = 0; k < nb_paths; k++){
            
            sum_payoff += option_->payoff(sim_prices[k][0]);
            squared_payoff += pow(option_->payoff(sim_prices[k][0]), 2);
        }
        
        current_estimate = exp(-r * T) * sum_payoff / NbPaths;

    }
    
    
}


double BlackScholesMCPricer::operator()() const{
    return current_estimate;
}



std::vector<double> BlackScholesMCPricer::confidenceInterval()
{

    if (NbPaths == 0){
        throw std::invalid_argument("Paths must be different to 0");
    }

    else {
        double var = (squared_payoff / NbPaths) - pow(sum_payoff / NbPaths, 2);
        double lower_bound = current_estimate - 1.96 * sqrt(var / NbPaths);
        double upper_bound = current_estimate + 1.96 * sqrt(var / NbPaths);
        vector<double> ci = { lower_bound, upper_bound };
        return ci;

    }

}



int BlackScholesMCPricer::getNbPaths() const{
    return NbPaths;
}