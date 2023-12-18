#include "CRRPricer.h"
#include "BinaryTree.cpp"

CRRPricer::CRRPricer(Option* opt, int depth, double asset_price, double up, double down, double interest_rate)
    : option(opt), N(depth), S0(asset_price), U(up), D(down), R(interest_rate) {
    if (down < -1 || down > up || interest_rate <= -1 || interest_rate > up) {
        std::cerr << "Arbitrage opportunity detected. Please adjust parameters." << std::endl;
        throw std::runtime_error("Arbitrage opportunity detected.");
    }
    if (down < -1 || asset_price<=0) {
        std::cerr << "Invalid parameters." << std::endl;
        throw std::runtime_error("Invalid parameters.");
    }
    tree.setDepth(depth);
}

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double r, double volatility)
    : option(option), N(depth), S0(asset_price)
{   
    double h = option->GetExpiry() / N;
    U = std::exp((r + std::pow(volatility, 2) / 2) * h + volatility * std::sqrt(h)) - 1;
    D = std::exp((r + std::pow(volatility, 2) / 2) * h - volatility * std::sqrt(h)) - 1;
    R = std::exp(r * h) - 1;

    if (D < -1 || D > U || R <= -1 || R > U) {
        std::cerr << "Arbitrage opportunity detected. Please adjust parameters." << std::endl;
        throw std::runtime_error("Arbitrage opportunity detected.");
    }
    if (asset_price <= 0) {
        std::cerr << "Invalid parameters." << std::endl;
        throw std::runtime_error("Invalid parameters.");
    }
    else if (option->isAsianOption()) {
        throw std::invalid_argument("Asian Option");
    }
    else if (option->isAmericanOption()) {
        exerciseTree.setDepth(N);
    }
    tree.setDepth(N);
}

bool CRRPricer::getExercise(int i, int j) {
    return exerciseTree.getNode(i, j);
}

    
double CRRPricer::get(int n, int i) 
{
    if (getExercise(n, i))
    {
        double q = (R - D) / (U - D);
        double up_factor = std::pow(U + 1, i);
        double down_factor = std::pow(D + 1, N - i);
        double stock_price = S0 * up_factor * down_factor;

        
        double intrinsic_value = option->payoff(stock_price);
        double continuous_value = (q * tree.getNode(n + 1, i + 1) + (1 - q) * tree.getNode(n + 1, i)) / (1 + R);

        return intrinsic_value >= continuous_value;

    }
    else
    {
        double q = (R - D) / (U - D);
        return (q * get(n + 1, i + 1) + (1 - q) * get(n + 1, i)) / (1 + R);
    }   
    
}

void CRRPricer::compute()
{
    for (int n = 0; n < N; n++)
    {
        for (int i = 0; i < n; i++)
        {
            tree.setNode(n,i,get(n,i));
        }
    }
        
}

double CRRPricer::operator()(bool closed_form) {
    if (closed_form) {
        double q = (R - D) / (U - D);
        double H00 = 0;

        for (int i = 0; i <= N; i++) {
            double up_factor = std::pow(U + 1, i);
            double down_factor = std::pow(D + 1, N - i);
            double stock_price = S0 * up_factor * down_factor;
            H00 += tgamma(N + 1) * pow(q, i) * pow(1 - q, N - i) * option->payoff(stock_price) / (tgamma(i + 1) * tgamma(N - i + 1));
        }

        H00 = H00 * (1 / pow(1 + R, N));
        return H00;
    }
    else {
        compute();
        return tree.getNode(0, 0);
    }


}


