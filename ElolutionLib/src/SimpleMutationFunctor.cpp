/*
 * SimpleMutationFunctor.cpp
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#include "SimpleMutationFunctor.h"
#include <random>

using namespace std;

namespace EAL {

SimpleMutationFunctor::SimpleMutationFunctor() {
	// TODO Auto-generated constructor stub

}

SimpleMutationFunctor::~SimpleMutationFunctor() {
	// TODO Auto-generated destructor stub
}

void SimpleMutationFunctor::operator()(IndividualPtr individual) {
	random_device rd;
	default_random_engine e1(rd());

	uniform_int_distribution<int> uniform_dist(0, individual->genesNo());
	int index = uniform_dist(e1);

	uniform_dist = uniform_int_distribution<int>(individual->minValue(), individual->maxValue());
	int newGene = uniform_dist(e1);

	individual->setGene(index, newGene);
}

} /* namespace EAL */
