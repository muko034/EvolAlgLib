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
	IIndividual(int genesNo, int minValue, int maxValue);
	virtual ~IIndividual();
//	IndividualPtr crossover(const IIndividual &other) const;
//	void mutate();
	double fitness() const;
	virtual bool isValid() { return true; }
	virtual IndividualPtr clone();

	int gene(int index) { return m_genotype[index]; }
	void setGene(int index, int value) { m_genotype[index] = value; }
	int genesNo() const { return m_genotype.size(); }
	int minValue() const { return m_minValue; }
	int maxValue() const { return m_maxValue; }

protected:
	virtual double calculateFitness() =0;

private:
	std::vector<int> m_genotype;
	int m_minValue;
	int m_maxValue;

};

} /* namespace EAL */

#endif /* IINDIVIDUAL_H_ */
