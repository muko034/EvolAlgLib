/*
 * FlipMutateFunctor.h
 *
 *  Created on: 28-01-2014
 *      Author: kuba
 */

#ifndef FLIPMUTATEFUNCTOR_H_
#define FLIPMUTATEFUNCTOR_H_

#include "MutateFunctor.h"
#include "IIndividual.h"

namespace EAL {

class FlipMutateFunctor: public EAL::MutateFunctor {
public:
	FlipMutateFunctor() {}
	virtual ~FlipMutateFunctor() {}
	virtual void operator()(IndividualPtr individual);
};

} /* namespace EAL */
#endif /* FLIPMUTATEFUNCTOR_H_ */
