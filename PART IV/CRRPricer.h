#ifndef CRRPricer_H
#define CRRPricer_H

#include "BinaryTree.h"
#include <cmath>
#include "Option.h"
#include "BinaryTree.cpp"

class CRRPricer {
private:
    Option* option;
    int N;
    double S0;
    double U, D, R;
    BinaryTree<double> tree;
    BinaryTree<bool> exerciseTree;

    

public:
    CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
    double get(int n, int i);
    double operator()(bool closed_form = false);
    CRRPricer(Option * option, int depth, double asset_price, double r, double volatility);
    ~CRRPricer() = default;
    bool getExercise(int n, int i);
    void compute();
};  

#endif