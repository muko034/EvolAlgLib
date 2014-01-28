/*
 * InvertMutateFunctor.h
 *
 *  Created on: 28-01-2014
 *      Author: kuba
 */

#ifndef INVERTMUTATEFUNCTOR_H_
#define INVERTMUTATEFUNCTOR_H_

#include "MutateFunctor.h"
#include "IIndividual.h"

namespace EAL {

class InvertMutateFunctor: public EAL::MutateFunctor {
public:
	InvertMutateFunctor() {}
	virtual ~InvertMutateFunctor() {}
	virtual void operator()(IndividualPtr individual);
};

} /* namespace EAL */
#endif /* INVERTMUTATEFUNCTOR_H_ */
