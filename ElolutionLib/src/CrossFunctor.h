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
typedef std::shared_ptr<IIndividual> IndividualPtr;

class CrossFunctor {
public:

	enum Type {
		ONE_POINTED = 0
	};

	CrossFunctor();
	virtual ~CrossFunctor();
	virtual IndividualPtr operator()(const IIndividual &other) =0;
};

} /* namespace EAL */

#endif /* CROSSFUNCTOR_H_ */
