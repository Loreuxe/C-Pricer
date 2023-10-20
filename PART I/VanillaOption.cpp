#include "VanillaOption.h"


using namespace std;


VanillaOption::VanillaOption(double expiry, double strike, OptionType optiontype){
    
    if(strike >= 0.0 && expiry >=0){

        _strike = strike;
        _optiontype = optiontype;
        Option(expiry);

    }
    else{
        cout<<"Arguments must be non negatives"<<endl;
    }
    


};