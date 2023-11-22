#include "BlackScholesMCPricer.h"
#include <cmath>
#include "stdexcept"
using namespace std;

BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility) : option_(option), initial_price_(initial_price), interest_rate_(interest_rate), volatility_(volatility) {
    if (option_ == nullptr) { throw invalid_argument("Option must be initialize as it's a pointer"); }
}

vector<double> BlackScholesMCPricer::generate(int nb_paths = 1) const {
    double S = initial_price_;
    double K = option_->GetStrike();
    double T = option_->GetExpiry();
    double r = interest_rate_;
    double sigma = volatility_;
    vector<double> time;
    vector<double> prices = { S };

    NbPaths += nb_paths;

    for (int i = 0; i < nb_paths; i++) {
        t.push_back(i);
    }

    if (option_->GetOptionNature() == OptionNature::Vanilla) {
        double z = MT::rand_norm();
        double s = prices[0] * exp((r - 0.5 * pow(sigma, 2)) * 1 + sigma * sqrt(1) * z);

        prices.push_back(s);
        return prices;
    }

    else if (option_->GetOptionNature() == OptionNature::Asian) {
        vector<double> time = AsianOption::getTimeSteps();
        for (int j = 1; j < nb_paths; j++) {
            double z = MT::rand_norm();
            double s = prices[j - 1] * exp((r - 0.5 * pow(sigma, 2)) * (t[j] - t[j - 1]) + sigma * sqrt(T[j] - T[j - 1]) * z);
            prices.push_back(s);
        }
        return prices;
    }
        
}



BlackScholesMCPricer::~BlackScholesMCPricer()
{
    // Release any dynamically allocated memory
    if (option_ != nullptr)
    {
        delete option_;
        option_ = nullptr; // Set the pointer to null to prevent double deletion.
    }
}

int BlackScholesMCPricer::getNbPaths() const{
    return NbPaths;
}