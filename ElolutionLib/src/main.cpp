//============================================================================
// Name        : main.cpp
// Author      : Kuba Ziec
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "IIndividual.h"
#include "Population.h"
#include "EvolutionAlg.h"

#include <random>
#include <list>
#include <memory>

using namespace std;
using namespace EAL;

class ClassA;

typedef shared_ptr<ClassA> APtr;

class ClassA {
public:
	ClassA(int x_) : x(x_) {}
	static bool comp(const APtr &a1, const APtr &a2) { return a1->x >= a2->x; }
	bool operator<(const APtr &other) { return this->x < other->x; }
	int x;
};

//bool comp(const APtr &a1, const APtr &a2) {
//	return a1->x < a2->x;
//}

class ConcrateIndividual : public IIndividual {
public:
	ConcrateIndividual() : IIndividual(1, 1, 30) {}
	ConcrateIndividual(ConcrateIndividual const *other) : IIndividual(other) {}
	virtual IndividualPtr clone() {
		return IndividualPtr(new ConcrateIndividual(this));
	}
protected:
	virtual double calculateFitness() const {
		int x = gene(0);
		return (x-5)*(x-5) + 100;
	}
};

int main() {
	cout << "!!!Hello World :) !!!" << endl; // prints !!!Hello World!!!


	IndividualPtr prototype(new ConcrateIndividual());
	Population population(100, prototype, CrossFunctor::Type::AVERAGE, MutateFunctor::Type::NONE, SelectFunctor::Type::ROULETTE);
	EvolutionAlg eal(population, 10);
	eal.start();
	cout << "!!!Bye World :( !!!" << endl;


//	SomeIndividual prototype;
//	Population population(100, prototype, ...);
//	EvolutionAlg evol(population);
//	evol.start();
//	evol.printResult();




	return 0;
}
