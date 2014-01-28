/*
 * FlipMutateFunctor.cpp
 *
 *  Created on: 28-01-2014
 *      Author: kuba
 */

#include "FlipMutateFunctor.h"
#include <random>

using namespace std;

namespace EAL {

void FlipMutateFunctor::operator()(IndividualPtr individual) {
	IndividualPtr copy_ = individual->clone();
	random_device rd;
	default_random_engine e1(rd());
	default_random_engine gen(rd());
	uniform_int_distribution<int> uniform_dist(0, individual->genesNo()-1);
	int i =-1, j =-1;
	int gene1, gene2;
	i = uniform_dist(e1);
	j = uniform_dist(e1);
	if (j == i) j = (j+1) % individual->genesNo();
	gene1 = individual->gene(i);
	gene2 = individual->gene(j);
	copy_->setGene(i, gene1);
	copy_->setGene(j, gene2);
	individual->setGene(i, gene1);
	individual->setGene(j, gene2);
}

} /* namespace EAL */
