#include "CRRPricer.h"

CRRPricer::CRRPricer(Option* opt, int depth, double asset_price, double up, double down, double interest_rate)
    : option(opt), N(depth), S0(asset_price), U(up), D(down), R(interest_rate) {
    if (depth <= 0 || up <= 0.0 || down <= 0.0 || interest_rate <= -1.0) {
        std::cerr << "Invalid input parameters." << std::endl;
    }
}

bool CRRPricer::has_arbitrage() {
    return (U <= 1.0 + R - D) || (U >= 1.0 + R - D);
}

void CRRPricer::compute() {
    if (has_arbitrage()) {
        std::cerr << "Arbitrage opportunity detected." << std::endl;
        return;
    }

    tree.setDepth(N);
    tree.setNode(0, 0, R);

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            double asset_up = tree.getNode(i - 1, j) * U;
            double asset_down = tree.getNode(i - 1, j) * D;
            tree.setNode(i, j, option->payoff(asset_up));
            tree.setNode(i, j + 1, option->payoff(asset_down));
        }
    }
}

double CRRPricer::get(int n, int i) {
    if (n < 0 || n >= N || i < 0 || i > n) {
        std::cerr << "Invalid node indices." << std::endl;
        return 0.0;
    }
    return tree.getNode(n, i);
}


double CRRPricer::S(int n, int i) {
    return S0 * pow(1 + U, i) * pow(1 + D, n - i);
}

double CRRPricer::operator()(bool closed_form) {
    if (closed_form) {
        double q = (R - D) / (U - D);
        double H00 = 0;

        for (int i = 0; i <= N; i++) {
            H00 += tgamma(N + 1) * pow(q, i) * pow(1 - q, N - i) * option->payoff(S(N, i)) / (tgamma(i + 1) * tgamma(N - i + 1));
        }

        H00 = H00 * (1 / pow(1 + R, N));
        return H00;
    } else {
        compute();
        return tree.getNode(0, 0);
    }
}


