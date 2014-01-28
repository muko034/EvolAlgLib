/*
 * AddCrossFunctor.h
 *
 *  Created on: 28-01-2014
 *      Author: kuba
 */

#ifndef ADDCROSSFUNCTOR_H_
#define ADDCROSSFUNCTOR_H_

#include "CrossFunctor.h"
#include "IIndividual.h"

namespace EAL {

class AddCrossFunctor : public EAL::CrossFunctor {
public:
	AddCrossFunctor() {}
	virtual ~AddCrossFunctor() {}
	virtual IndividualPtr operator()(const IndividualPtr mommy, const IndividualPtr daddy);
};

} /* namespace EAL */
#endif /* ADDCROSSFUNCTOR_H_ */
