/*
 * RouletteSelectFunctor.cpp
 *
 *  Created on: 26-01-2014
 *      Author: kuba
 */

#include "RouletteSelectFunctor.h"

using namespace std;

namespace EAL {

RouletteSelectFunctor::RouletteSelectFunctor() {
//	m_randomEngine = default_random_engine(m_rd());
//	uniform_real_distribution<double> uniform_dist(0.0, 1.0);
//	double random = uniform_dist(m_randomEngine);

}

RouletteSelectFunctor::~RouletteSelectFunctor() {
	// TODO Auto-generated destructor stub
}

IndividualPtr RouletteSelectFunctor::operator()(std::list<IndividualPtr> individuals) const {
	// TODO klasa do generowania liczb losowych

	random_device rd;
	default_random_engine gen(rd());
	uniform_real_distribution<double> dis(0.0, 1.0);
	double random = dis(gen);

	double sum = 0.0;
	for (IndividualPtr ind : individuals) {
		sum += ind->fitness();
	}

	individuals.sort(IIndividual::rcomp); // FIXME w kolejności malejącej

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
