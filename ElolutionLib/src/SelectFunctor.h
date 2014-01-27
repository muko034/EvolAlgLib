/*
 * SelectFunctor.h
 *
 *  Created on: 26-01-2014
 *      Author: kuba
 */

#ifndef SELECTFUNCTOR_H_
#define SELECTFUNCTOR_H_

#include <memory>
#include <list>

namespace EAL {

class IIndividual;
typedef std::shared_ptr<IIndividual> IndividualPtr;

class SelectFunctor {
public:

	enum Type {
		NONE = 0,
		ROULETTE,
//		ONE_POINTED
	};

	SelectFunctor();
	virtual ~SelectFunctor();
	virtual IndividualPtr operator()(const std::list<IndividualPtr> individuals) const =0;
};

} /* namespace EAL */
#endif /* SELECTFUNCTOR_H_ */
