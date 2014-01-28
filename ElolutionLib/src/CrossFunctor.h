/*
 * CrossFunctor.h
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#ifndef CROSSFUNCTOR_H_
#define CROSSFUNCTOR_H_

#include <memory>

namespace EAL {

class IIndividual;
class CrossFunctor;
typedef std::shared_ptr<IIndividual> IndividualPtr;
typedef std::shared_ptr<CrossFunctor> CFunPtr;

class CrossFunctor {
public:
	CrossFunctor() {}
	virtual ~CrossFunctor() {}
	virtual IndividualPtr operator()(const IndividualPtr mommy, const IndividualPtr daddy) =0;
};

} /* namespace EAL */

#endif /* CROSSFUNCTOR_H_ */
