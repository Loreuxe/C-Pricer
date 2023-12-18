#ifndef MT_H
#define MT_H
#include <random>

class MT {
private:
    MT();
    ~MT();

    MT(const MT&) = delete;
    MT& operator=(const MT&) = delete;

    static MT& seed();
    std::mt19937 generator;

public:
	static double rand_unif();
	static double rand_norm();

};
#endif // MT_H
