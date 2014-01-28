/*
 * EmptyMutateFunctor.h
 *
 *  Created on: 26-01-2014
 *      Author: kuba
 */

#ifndef EMPTYMUTATEFUNCTOR_H_
#define EMPTYMUTATEFUNCTOR_H_

#include "MutateFunctor.h"

namespace EAL {

class EmptyMutateFunctor: public EAL::MutateFunctor {
public:
	EmptyMutateFunctor() {}
	virtual ~EmptyMutateFunctor() {}
	virtual void operator()(IndividualPtr individual) { }
};

} /* namespace EAL */
#endif /* EMPTYMUTATEFUNCTOR_H_ */
