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
class SelectFunctor;
typedef std::shared_ptr<IIndividual> IndividualPtr;
typedef std::shared_ptr<SelectFunctor> SFunPtr;

class SelectFunctor {
public:
	SelectFunctor() {}
	virtual ~SelectFunctor() {}
	virtual IndividualPtr operator()(const std::list<IndividualPtr> individuals) const =0;
};

} /* namespace EAL */
#endif /* SELECTFUNCTOR_H_ */
