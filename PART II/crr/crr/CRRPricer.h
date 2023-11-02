#pragma once
#include "BinaryTree.h"
#include <cmath>
#include "Option.h"

class CRRPricer {
private:
    Option* option;
    int N;
    double S0;
    double U, D, R;
    BinaryTree<int> tree;

    bool has_arbitrage();
    void compute();

public:
    CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
    double get(int n, int i);
    double operator()(bool closed_form = false);
    double S(int n, int i);

};
