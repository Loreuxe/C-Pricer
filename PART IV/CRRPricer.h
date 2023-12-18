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
    BinaryTree<double> tree;
    BinaryTree<bool> exercise;
   
    void compute();

public:
    CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
    CRRPricer(Option * option, int depth, double asset_price, double r, double volatility);
    double get(int n, int i);
    double operator()(bool closed_form = false);
    bool getExercise(int i, int j);
    
    ~CRRPricer() = default;
};