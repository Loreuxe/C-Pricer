#pragma once 

class Option
{

    public: 
        explicit Option(double expiry);
        const double GetExpiry() ;
        virtual double payoff(double price) const = 0;
        virtual ~Option();
    private:
        double _expiry;

};
enum class OptionType {
    Call,
    Put
};

class VanillaOption : public Option {
private:
    double _strike;
    OptionType _optiontype;
public:
    VanillaOption(double expiry, double strike);
    virtual  OptionType GetOptionType() const = 0;
    double GetStrike() const;
};
class VanillaCallOption : public VanillaOption {
public:
    VanillaCallOption(double expiry, double strike);
    OptionType GetOptionType() const override;
    double payoff(double z) const override;
};
class VanillaPutOption : public VanillaOption {
public:
    VanillaPutOption(double expiry, double strike);
    OptionType GetOptionType() const override;
    double payoff(double z) const override;
};
class DigitalOption : public Option {
protected:
    double _strike;

public:
    DigitalOption(double expiry, double strike);
    double GetStrike() const;
    virtual double payoff(double z) const = 0;
};

class DigitalCallOption : public DigitalOption {
public:
    DigitalCallOption(double expiry, double strike);
    double payoff(double z) const override;
};

class DigitalPutOption : public DigitalOption {
public:
    DigitalPutOption(double expiry, double strike);
    double payoff(double z) const override;
};
