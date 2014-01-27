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
#include "SelectFunctorFactory.h"
#include "CrossFunctor.h"
#include "MutateFunctor.h"
#include "SelectFunctor.h"


namespace EAL {

class EvolutionAlg;

class Population {
	friend class EvolutionAlg;
public:
	Population();
	Population(int popSize, IndividualPtr prototype, CrossFunctor::Type crossFun, MutateFunctor::Type mutateFun, SelectFunctor::Type selFun);
	virtual ~Population();
	IndividualPtr selectOne() const;
	void add(std::list<IndividualPtr> &individuals);
	int size() const { return m_size; }

protected:
	virtual void generateInitialIndividuals(const IndividualPtr prototype);
	IndividualPtr crossover(const IndividualPtr mommy, const IndividualPtr daddy);
	void mutate(IndividualPtr individual);


private:
	static CrossFunctorFactory s_crossFunFactory;
	static MutateFunctorFactory s_mutateFunFactory;
	static SelectFunctorFactory s_selectFunFactory;

	std::list<IndividualPtr> m_individuals;
	std::shared_ptr<CrossFunctor> m_crossFunctor;
	std::shared_ptr<MutateFunctor> m_mutateFunctor;
	std::shared_ptr<SelectFunctor> m_selectFunctor;
	int m_size;
	IndividualPtr m_theBestOne;
};

} /* namespace EAL */
#endif /* POPULATE_H_ */
