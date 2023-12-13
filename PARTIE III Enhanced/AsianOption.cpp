#include "AsianOption.h"
using namespace std;

AsianOption::AsianOption(vector<double> time) :_time(time) {}

OptionNature AsianOption::GetOptionNature() const { return OptionNature::Asian; }

vector<double> AsianOption::getTimeSteps() const { return _time; }

bool AsianOption::isAsianOption() {
	if (GetOptionNature() == OptionNature::Asian) { return true; }
	else { return false; }
}

double AsianOption::GetExpiry() const {
	return 0.0;
}

double AsianOption::GetStrike() const { return 0.0; }



