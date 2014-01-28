/*
 * AddCrossFunctor.cpp
 *
 *  Created on: 28-01-2014
 *      Author: kuba
 */

#include "AddCrossFunctor.h"

using namespace std;

namespace EAL {

IndividualPtr AddCrossFunctor::operator()(const IndividualPtr mommy, const IndividualPtr daddy) {
	IndividualPtr child = mommy->clone();
	int mommysGene, daddysGene, gene;
	for (int i=0; i < mommy->genesNo(); ++i) {
		mommysGene = mommy->gene(i);
		daddysGene = daddy->gene(i);
		gene = mommysGene + daddysGene;
		child->setGene(i, gene);
	}
//	TODO if (!child->isValid()) throw ...;
	return child;
}

} /* namespace EAL */
