/*
 * SimpleMutationFunctor.cpp
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#include "SimpleMutationFunctor.h"
#include <iostream>
#include <random>
#include <cmath>

using namespace std;

namespace EAL {

//SimpleMutationFunctor::SimpleMutationFunctor() {
//	// TODO Auto-generated constructor stub
//
//}

SimpleMutationFunctor::~SimpleMutationFunctor() {
	// TODO Auto-generated destructor stub
}

void SimpleMutationFunctor::operator()(IndividualPtr individual) {
	IndividualPtr copy_ = individual->clone();
	random_device rd;
	default_random_engine e1(rd());
	default_random_engine gen(rd());
	uniform_int_distribution<int> uniform_dist(0, individual->genesNo()-1);
	uniform_real_distribution<double> dis(m_mean, m_stddev);
	int index =-1;
	int newGene = -1;
	double random = 0.0;
	do {
		index = uniform_dist(e1);
		random = dis(gen);
		newGene = individual->gene(index) + round(random);
//		cout	<<" oldGene: "<<individual->gene(index)
//				<<" newGene: "<<newGene
//				<<" index: "<<index
//				<<endl;
		copy_->setGene(index, newGene);
	} while (!copy_->isValid());
	individual->setGene(index, newGene);
}

} /* namespace EAL */
