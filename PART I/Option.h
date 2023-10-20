#ifndef OPTION_H 
#define OPTION_H


class Option
{

    public: 
        Option(double expiry);
        const double getExpiry() ;
        virtual double payoff(double price);

    private:
        double _expiry;

}

#endif /* OPTION_H */