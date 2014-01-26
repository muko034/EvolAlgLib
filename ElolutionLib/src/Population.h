/*
 * Populate.h
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#ifndef POPULATE_H_
#define POPULATE_H_

#include <list>
#include <memory>
#include "IIndividual.h"
#include "CrossFunctorFactory.h"
#include "MutateFunctorFactory.h"
#include "CrossFunctor.h"
#include "MutateFunctor.h"

namespace EAL {

class Population {
public:
	Population();
	Population(int popSize, IndividualPtr prototype, CrossFunctor::Type crossFun, MutateFunctor::Type mutateFun);
	virtual ~Population();

protected:
	virtual void generateInitialIndividuals(const IndividualPtr prototype);
	IndividualPtr crossover(const IndividualPtr mommy, const IndividualPtr daddy);
	void mutate(IndividualPtr individual);

private:
	static CrossFunctorFactory s_crossFunFactory;
	static MutateFunctorFactory s_mutateFunFactory;

	std::list<IndividualPtr> m_individuals;
	std::shared_ptr<CrossFunctor> m_crossFunctor;
	std::shared_ptr<MutateFunctor> m_mutateFunctor;
	int m_size;
};

} /* namespace EAL */
#endif /* POPULATE_H_ */
