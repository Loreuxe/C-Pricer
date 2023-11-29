#include "AsianOption.h"
using namespace std;

AsianOption::AsianOption(double expiry, vector<double> time, double strike) : Option(expiry), _time(time), _strike(strike) {

	if (_strike < 0.0) { throw invalid_argument("Strike must be non negative"); }

}

OptionNature AsianOption::GetOptionNature() const { return OptionNature::Asian; }

vector<double> AsianOption::getTimeSteps() const { return _time; }


bool AsianOption::isAsianOption() {
	if (GetOptionNature() == OptionNature::Asian) { return true; }
}

double AsianOption::GetStrike() const { return _strike; }