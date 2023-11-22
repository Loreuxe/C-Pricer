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
double CRRPricer::get(int n, int i) {
    double q = (R - D) / (U - D);
    double up_factor = std::pow(U + 1, i);
    double down_factor = std::pow(D + 1, N - i);
    double stock_price = S0 * up_factor * down_factor;
    
    if (n + 1 <= N) 
        return (q * get(n + 1, i + 1) + (1 - q) * get(n + 1, i)) / (1 + R);
    else
        return option->payoff(stock_price);

        
}

void CRRPricer::compute() {

    for (int n = 0; n < N; ++n) {
        for (int i = 0; i <= n; ++i) {
            tree.setNode(n, i,get(n,i));
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
    } else {
        compute();
        return tree.getNode(0, 0);
    }
}


