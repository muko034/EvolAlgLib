/*
 * SimpleMutationFunctor.h
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#ifndef SIMPLEMUTATIONFUNCTOR_H_
#define SIMPLEMUTATIONFUNCTOR_H_

#include "MutateFunctor.h"
#include "IIndividual.h"

namespace EAL {

class SimpleMutationFunctor: public EAL::MutateFunctor {
public:
	SimpleMutationFunctor();
	virtual ~SimpleMutationFunctor();
	virtual void operator()(IndividualPtr individual);
};

} /* namespace EAL */
#endif /* SIMPLEMUTATIONFUNCTOR_H_ */
