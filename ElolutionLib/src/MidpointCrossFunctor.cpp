/*
 * MidpointCrossFunctor.cpp
 *
 *  Created on: 28-01-2014
 *      Author: kuba
 */

#include "MidpointCrossFunctor.h"
#include <random>

namespace EAL {

using namespace std;

IndividualPtr MidpointCrossFunctor::operator()(const IndividualPtr mommy, const IndividualPtr daddy) {
	IndividualPtr child = mommy->clone();
	int gene;

	random_device rd;
	default_random_engine e1(rd());
	uniform_int_distribution<int> uniform_dist(0, mommy->genesNo()-1);
	int midpoint = uniform_dist(e1);

	for (int i=0; i < mommy->genesNo(); ++i) {
		if (i < midpoint) {
			gene = mommy->gene(i);
		} else {
			gene = daddy->gene(i);
		}
		child->setGene(i, gene);
	}
//	TODO if (!child->isValid()) throw ...;
	return child;
}

} /* namespace EAL */
