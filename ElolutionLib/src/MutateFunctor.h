/*
 * MutateFunctor.h
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#ifndef MUTATEFUNCTOR_H_
#define MUTATEFUNCTOR_H_

#include <memory>

namespace EAL {

class IIndividual;
class MutateFunctor;

typedef std::shared_ptr<IIndividual> IndividualPtr;
typedef std::shared_ptr<MutateFunctor> MFunPtr;

class MutateFunctor {
public:
	MutateFunctor() {}
	virtual ~MutateFunctor() {}
	virtual void operator()(IndividualPtr individual) =0;
};

} /* namespace EAL */

#endif /* MUTATEFUNCTOR_H_ */
