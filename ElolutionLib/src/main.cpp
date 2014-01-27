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
#include "SimpleMutationFunctor.h"

#include <random>
#include <list>
#include <vector>
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
	ConcrateIndividual() : IIndividual(2) {}
	ConcrateIndividual(vector<int> &genes) : IIndividual(genes) {}
	ConcrateIndividual(ConcrateIndividual const *other) : IIndividual(other) {}
	virtual IndividualPtr clone() { return IndividualPtr(new ConcrateIndividual(this)); }
	virtual IndividualPtr makeRandomClone() {
		random_device rd;
		default_random_engine e1(rd());
		uniform_int_distribution<int> uniform_dist(1, 30);
		vector<int> genes;
		for(int i=0; i<genesNo(); ++i) {
			genes.push_back(uniform_dist(e1));
		}
		return IndividualPtr(new ConcrateIndividual(genes));
	}
	virtual bool isValid() {
		vector<int> genotype = this->genotype();
		for (int gene : genotype) {
			if (gene < 1 || gene > 30)
				return false;
		}
		return true;
	}
protected:
	virtual double calculateFitness() const {
		int x = gene(0);
		int y = gene(1);
		return (x - 5)*(x - 5)*(x - 5) + x*x - x*y + y*y + 100;
	}
};

int main() {
	cout << "!!!Hello World :) !!!" << endl; // prints !!!Hello World!!!


	IndividualPtr prototype(new ConcrateIndividual());
	Population population( 10, prototype, 0.5,
						   CrossFunctor::Type::AVERAGE,
						   MFunPtr(new SimpleMutationFunctor(0.0, 5.0)),
						   SelectFunctor::Type::ROULETTE );
	EvolutionAlg eal(population, 20);
	eal.start();
	cout << "!!!Bye World :( !!!" << endl;


//	SomeIndividual prototype;
//	Population population(100, prototype, ...);
//	EvolutionAlg evol(population);
//	evol.start();
//	evol.printResult();




	return 0;
}
