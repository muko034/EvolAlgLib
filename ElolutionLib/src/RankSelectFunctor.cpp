/*
 * RankSelectFunctor.cpp
 *
 *  Created on: 28-01-2014
 *      Author: kuba
 */

#include "RankSelectFunctor.h"
#include <random>
#include <iostream>

using namespace std;

namespace EAL {

IndividualPtr RankSelectFunctor::operator()(std::list<IndividualPtr> individuals) const {
	random_device rd;
	default_random_engine gen(rd());
	uniform_real_distribution<double> dis(0.0, 1.0);
	double random = dis(gen);

	unsigned sum = 0;
	for (unsigned i=0; i<individuals.size(); ++i) {
		sum += i+1;
	}

	individuals.sort(IIndividual::rcomp);

	double chance;
	int rank=individuals.size();
	for (IndividualPtr ind : individuals) {
		chance = (double) rank/sum;
		if (random <= chance) {

			return ind;
		}
		random -= chance;
		--rank;
	}

	// TODO throw
	return IndividualPtr();
}

} /* namespace EAL */
