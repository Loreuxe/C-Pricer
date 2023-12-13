#include "BlackScholesMCPricer.h"
#include "BlackScholesPricer.h"
#include <cmath>
#include "stdexcept"
using namespace std;

BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility) : option_(option), initial_price_(initial_price), interest_rate_(interest_rate), volatility_(volatility) {}


void BlackScholesMCPricer::generate(int nb_paths = 1) {
    double S = initial_price_;
    double K = option_ -> GetStrike();
    double T = option_ -> GetExpiry();
    double r = interest_rate_;
    double sigma = volatility_;
    

    NbPaths += nb_paths;

    std::vector<std::vector<double>> vect_sim;

    for (int k = 0; k < nb_paths; k++) {

        if (option_->GetOptionNature() == OptionNature::Vanilla || option_->GetOptionNature() == OptionNature::Digital) {

            double z = MT::rand_norm();
            double s = S * exp((r - 0.5 * pow(sigma, 2)) * 1 + sigma * sqrt(1) * z);
            vector<double> v = { s };
            vect_sim.push_back(v);
        }

        if (option_->GetOptionNature() == OptionNature::Asian) {

            vector<double> t = option_->getTimeSteps(); //On veut chopper le fixing_dates du main.cpp

            double z = MT::rand_norm();
            vector<double> prices = { S };

            for (size_t j = 1; j < t.size(); j++) {

                double z = MT::rand_norm();
                double s = prices[j - 1] * exp((r - 0.5 * pow(sigma, 2)) * (t[j] - t[j - 1]) + sigma * sqrt(t[j] - t[j - 1]) * z);
                prices.push_back(s);

            }
            vect_sim.push_back(prices);

            
        }

    }
    if (option_->GetOptionNature() == OptionNature::Asian) {
        for (size_t i = 0; i<vect_sim.size(); i++) {
            current_estimate += option_->payoffPath(vect_sim[i]);
            squared_payoff += pow(option_->payoffPath(vect_sim[i]), 2);
        }
        vector<double> t = option_->getTimeSteps();
        current_estimate = exp(-r * t[t.size() - 1]) * current_estimate / nb_paths;
    }
    else {
        for (size_t i = 0; i<vect_sim.size(); i++) {
            current_estimate += option_->payoff(vect_sim[i][0]);
            squared_payoff += pow(option_->payoff(vect_sim[i][0]), 2);

        }
        //cout << getNbPaths;
        current_estimate = exp(-r * T) * current_estimate / nb_paths;

    }
    
    
}


double BlackScholesMCPricer::operator()() const{
    return current_estimate;
}


std::vector<double> BlackScholesMCPricer::confidenceInterval()
{
    vector<double> ci;

    if (NbPaths == 0)
    {
        throw std::invalid_argument("Paths must be different to 0");
    }

    double var = (squared_payoff / NbPaths) - pow(current_estimate, 2);
    double lower_bound = current_estimate - 1.96 * sqrt(var / NbPaths);
    double upper_bound = current_estimate + 1.96 * sqrt(var / NbPaths);

    ci = { lower_bound, upper_bound };
    return ci;

}



int BlackScholesMCPricer::getNbPaths() const{
    return NbPaths;
}