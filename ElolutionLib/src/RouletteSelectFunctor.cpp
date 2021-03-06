/*
 * RouletteSelectFunctor.cpp
 *
 *  Created on: 26-01-2014
 *      Author: kuba
 */

#include "RouletteSelectFunctor.h"
#include <random>

using namespace std;

namespace EAL {

IndividualPtr RouletteSelectFunctor::operator()(std::list<IndividualPtr> individuals) const {
	random_device rd;
	default_random_engine gen(rd());
	uniform_real_distribution<double> dis(0.0, 1.0);
	double random = dis(gen);

	double sum = 0.0;
	for (IndividualPtr ind : individuals) {
		sum += ind->fitness();
	}

	individuals.sort(IIndividual::rcomp);

	double chance;
	for (IndividualPtr ind : individuals) {
		chance = ind->fitness()/sum;
		if (random <= chance)
			return ind;
		random -= chance;
	}
	return IndividualPtr();
}

} /* namespace EAL */
