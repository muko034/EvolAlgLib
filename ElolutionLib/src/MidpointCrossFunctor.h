/*
 * MidpointCrossFunctor.h
 *
 *  Created on: 28-01-2014
 *      Author: kuba
 */

#ifndef MIDPOINTCROSSFUNCTOR_H_
#define MIDPOINTCROSSFUNCTOR_H_

#include "CrossFunctor.h"
#include "IIndividual.h"

namespace EAL {

class MidpointCrossFunctor: public EAL::CrossFunctor {
public:
	MidpointCrossFunctor() {}
	virtual ~MidpointCrossFunctor() {}
	virtual IndividualPtr operator()(const IndividualPtr mommy, const IndividualPtr daddy);
};

} /* namespace EAL */
#endif /* MIDPOINTCROSSFUNCTOR_H_ */
