//============================================================================
// Name        : main.cpp
// Author      : Kuba Ziec
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "EAL.h"

#include <random>
#include <list>
#include <vector>
#include <memory>
#include <string>

using namespace std;
using namespace EAL;

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
						   CFunPtr(new AverageCrossFunctor()),
						   MFunPtr(new SimpleMutationFunctor(0.0, 5.0)),
						   SFunPtr(new RankSelectFunctor()) );
	EvolutionAlg eal(population, 20);
	eal.start();
	eal.theBestOne()->print();

	cout << "!!!Bye World :( !!!" << endl;
	return 0;
}
