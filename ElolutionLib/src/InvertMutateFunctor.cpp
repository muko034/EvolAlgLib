/*
 * InvertMutateFunctor.cpp
 *
 *  Created on: 28-01-2014
 *      Author: kuba
 */

#include "InvertMutateFunctor.h"
#include <random>

using namespace std;

namespace EAL {

void InvertMutateFunctor::operator()(IndividualPtr individual) {
	IndividualPtr copy_ = individual->clone();
	random_device rd;
	default_random_engine e1(rd());
	default_random_engine gen(rd());
	uniform_int_distribution<int> uniform_dist(0, individual->genesNo()-1);
	int i =-1;
	int gene;
	i = uniform_dist(e1);
	gene = -(individual->gene(i));
	copy_->setGene(i, gene);
	individual->setGene(i, gene);
}

} /* namespace EAL */
