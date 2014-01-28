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
#include <string>
#include "CrossFunctor.h"
#include "MutateFunctor.h"

namespace EAL {

class IIndividual;

typedef std::shared_ptr<IIndividual> IndividualPtr;

class IIndividual {
public:
	IIndividual(int genesNo);
	IIndividual(std::vector<int> &vec);
	IIndividual(IIndividual const *other);
	virtual ~IIndividual() {}

	static bool comp(const IndividualPtr &i1, const IndividualPtr &i2) { return i1->fitness() < i2->fitness(); }
	static bool rcomp(const IndividualPtr &i1, const IndividualPtr &i2) { return i1->fitness() >= i2->fitness(); }

	double fitness() const;
	std::string toString() const;
	void print();
	virtual bool isValid() { return true; }
	virtual IndividualPtr clone() =0;
	virtual IndividualPtr makeRandomClone() =0;

	int gene(int index) const { return m_genotype[index]; }
	std::vector<int> genotype() const { return m_genotype; }
	void setGene(int index, int value);
	int genesNo() const { return m_genotype.size(); }

protected:
	virtual double calculateFitness() const =0;

private:
	std::vector<int> m_genotype;
	mutable double m_fitnessValue;

};

} /* namespace EAL */

#endif /* IINDIVIDUAL_H_ */
