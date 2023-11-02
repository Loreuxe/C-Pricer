#include "VanillaOption.h"
#include "CallOption.h"  // Include the CallOption header
#include "PutOption.h"   // Include the PutOption header
#include "BlackScholesPricer.h"
#include <iostream>

int main() {
    // Create instances of derived classes, not the base class
    CallOption callOption(1.0, 100.0);
    PutOption putOption(1.0, 100.0);
    BlackScholesPricer pricer(&callOption, 105.0, 0.05, 0.2);

    double optionPrice = pricer();
    double optionDelta = pricer.delta();

    std::cout << "Call Option Price: " << optionPrice << std::endl;
    std::cout << "Call Option Delta: " << optionDelta << std::endl;

    return 0;
}