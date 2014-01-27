/*
 * AverageCrossFunctor.cpp
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#include "AverageCrossFunctor.h"
#include <cmath>
#include <iostream>

using namespace std;

namespace EAL {

AverageCrossFunctor::AverageCrossFunctor() {
	// TODO Auto-generated constructor stub

}

AverageCrossFunctor::~AverageCrossFunctor() {
	// TODO Auto-generated destructor stub
}

IndividualPtr AverageCrossFunctor::operator()(const IndividualPtr mommy, const IndividualPtr daddy) {
	IndividualPtr child = mommy->clone();
	int mommysGene, daddysGene, gene;
	for (int i=0; i < mommy->genesNo(); ++i) {
		mommysGene = mommy->gene(i);
		daddysGene = daddy->gene(i);
		gene = round((mommysGene + daddysGene)/2);
//		cout 	<< " mommysGene " << mommysGene
//				<< " daddysGene "<< daddysGene
//				<< " gene "<< gene
//				<<endl;
		child->setGene(i, gene);
	}
//	TODO if (!child->isValid()) throw ...;
	return child;
}

} /* namespace EAL */
