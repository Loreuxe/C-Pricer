#include "Option.h"
#include "VanillaOption.h"
#include "CallOption.h"  // Include the CallOption header
#include "PutOption.h"   // Include the PutOption header
#include "AmericanOption.h"
#include "AmericanCallOption.h"
#include "AmericanPutOption.h"
#include "DigitalOption.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"
#include "AsianOption.h"
#include "AsianCallOption.h"
#include "AsianPutOption.h"
#include "BlackScholesPricer.h"
#include "MT.h"
#include <iostream>


int main() {
    // Create instances of derived classes, not the base class
    CallOption callOption(1.0, 100.0);
    PutOption putOption(1.0, 100.0);
    DigitalPutOption digit(1.0, 100.0);
    BlackScholesPricer pricer(&callOption, 105.0, 0.05, 0.2);
    BlackScholesPricer pricerd(&digit, 105.0, 0.05, 0.2);

    AmericanCallOption(1.0, 100);

    double optionPrice = pricer();
    double optionDelta = pricer.delta();
    double optiondigit = pricerd();


    std::cout << "Call Option Price: " << optionPrice << std::endl;
    std::cout << "Call Option Delta: " << optionDelta << std::endl;
    std::cout << "Call digit Price: " << optiondigit << std::endl;

    std::cout << "Uniform random number: " << MT::rand_unif() << std::endl;
    std::cout << "Normal random number: " << MT::rand_norm() << std::endl;



    return 0;
}