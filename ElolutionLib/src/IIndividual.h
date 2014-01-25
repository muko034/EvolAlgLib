/*
 * IIndividual.h
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#ifndef IINDIVIDUAL_H_
#define IINDIVIDUAL_H_

#include <vector>
#include <memory>
#include "CrossFunctorFactory.h"
#include "MutateFunctorFactory.h"
#include "CrossFunctor.h"
#include "MutateFunctor.h"

namespace EAL {

class IIndividual;

typedef std::shared_ptr<IIndividual> IndividualPtr;

class IIndividual {
public:
	IIndividual();
	IIndividual(CrossFunctor::Type crossFun, MutateFunctor::Type mutateFun);
	virtual ~IIndividual();
	IndividualPtr crossover(const IIndividual &other) const;
	void mutate();
	double fitness() const;

	int gene(int index) { return m_genotype[index]; }
	void setGene(int index, int value) { m_genotype[index] = value; }

protected:
	virtual double calculateFitness() =0;

private:
	static CrossFunctorFactory m_crossFunFactory;
	static MutateFunctorFactory m_mutateFunFactory;

	std::vector<int> m_genotype;
	std::shared_ptr<CrossFunctor> m_crossFunctor;
	std::shared_ptr<MutateFunctor> m_mutateFunctor;

};

} /* namespace EAL */

#endif /* IINDIVIDUAL_H_ */
