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
            cout << "check Vanilla or Digital" << endl;

            double z = MT::rand_norm();
            double s = S * exp((r - 0.5 * pow(sigma, 2)) * 1 + sigma * sqrt(1) * z);
            cout << s << endl;
            vector<double> prices = { s };
            vect_sim.push_back(prices);
            //current_estimate = exp(-r * T) * option_->payoff(s) / nb_paths;
            //cout << "current estimate : " << current_estimate << endl;

        }

        if (option_->GetOptionNature() == OptionNature::Asian) {
            cout << "check Asian" << endl;

            vector<double> t = option_->getTimeSteps(); //On veut chopper le fixing_dates du main.cpp

            double z = MT::rand_norm();
            vector<double> prices = { S };

            for (int j = 1; j < t.size(); j++) {

                //cout << j << endl;
                double z = MT::rand_norm();
                double s = prices[j - 1] * exp((r - 0.5 * pow(sigma, 2)) * (t[j] - t[j - 1]) + sigma * sqrt(t[j] - t[j - 1]) * z);
                prices.push_back(s);
                //cout << s << endl;

            }
            prices.erase(prices.begin());
            vect_sim.push_back(prices);

            
        }

    }
    if (option_->GetOptionNature() == OptionNature::Asian) {
        for (int i = 0; i<vect_sim.size(); i++) {
            current_estimate += option_->payoffPath(vect_sim[i]);
        }
        vector<double> t = option_->getTimeSteps();
        current_estimate = exp(-r * t[t.size() - 1]) * current_estimate / nb_paths;
        cout << "current estimate : " << current_estimate << endl;
    }
    else {
        for (int i = 0; i<vect_sim.size(); i++) {
            current_estimate += option_->payoff(vect_sim[i][0]);
        }
        current_estimate = exp(-r * T) * current_estimate / nb_paths;
        cout << "current estimate : " << current_estimate << endl;
    }
    
    
}


double BlackScholesMCPricer::operator()() const{
    return current_estimate;
}


std::vector<double> BlackScholesMCPricer::confidenceInterval()
{

    if (NbPaths == 0)
    {
        throw std::invalid_argument("Paths must be different to 0");
    }

    double mean = 0;
    double ecart_type = 0;

    for (int k = 0; k < NbPaths; k++) { 
        mean += prices[k];
    }
    mean = mean / prices.size();
   
    for (int i = 0; i < prices.size(); i++)
    {
        ecart_type += prices[i] - mean;
    }

    double lower_bound = mean - 1.96 * sqrt(ecart_type / prices.size());
    double upper_bound = mean + 1.96 * sqrt(ecart_type / prices.size());

    vector <double> ci = { lower_bound, upper_bound };
    return ci;

}


BlackScholesMCPricer::~BlackScholesMCPricer()
{
    // Release any dynamically allocated memory
    if (option_ != nullptr)
    {
        delete option_;
    }
}

int BlackScholesMCPricer::getNbPaths() const{
    return NbPaths;
}