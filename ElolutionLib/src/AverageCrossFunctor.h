/*
 * AverageCrossFunctor.h
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#ifndef AVERAGECROSSFUNCTOR_H_
#define AVERAGECROSSFUNCTOR_H_

#include "CrossFunctor.h"
#include "IIndividual.h"

namespace EAL {

class AverageCrossFunctor : public CrossFunctor {
public:
	AverageCrossFunctor() {}
	virtual ~AverageCrossFunctor() {}
	virtual IndividualPtr operator()(const IndividualPtr mommy, const IndividualPtr daddy);
};

} /* namespace EAL */
#endif /* AVERAGECROSSFUNCTOR_H_ */
