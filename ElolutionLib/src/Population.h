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
#include "CrossFunctor.h"
#include "MutateFunctor.h"
#include "SelectFunctor.h"


namespace EAL {

class EvolutionAlg;

class Population {
	friend class EvolutionAlg;
public:
	Population(int popSize,
			   IndividualPtr prototype,
			   double mutationChange,
			   CFunPtr crossFun,
			   MFunPtr mutateFun,
			   SFunPtr selFun);
	virtual ~Population();
	IndividualPtr selectOne() const;
	void add(std::list<IndividualPtr> &individuals);
	int size() const { return m_size; }
	IndividualPtr theBestOne() { return m_theBestOne; }
	void print();

protected:
	virtual void generateInitialIndividuals(const IndividualPtr prototype);
	IndividualPtr crossover(const IndividualPtr mommy, const IndividualPtr daddy);
	void mutate(IndividualPtr individual);


private:
	std::list<IndividualPtr> m_individuals;
	std::shared_ptr<CrossFunctor> m_crossFunctor;
	std::shared_ptr<MutateFunctor> m_mutateFunctor;
	std::shared_ptr<SelectFunctor> m_selectFunctor;
	int m_size;
	double m_mutationChange;
	IndividualPtr m_theBestOne;
};

} /* namespace EAL */
#endif /* POPULATE_H_ */
