/*
 * IIndividual.cpp
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#include "IIndividual.h"
#include <iostream>

using namespace std;

namespace EAL {

IIndividual::IIndividual(IIndividual const *other) :
		m_genotype(other->m_genotype),
		m_fitnessValue(other->m_fitnessValue)
{

}

IIndividual::IIndividual(int genesNo) :
		m_fitnessValue(-1)
{
	for (int i=0; i<genesNo; ++i) m_genotype.push_back(0);

}

IIndividual::IIndividual(std::vector<int> &vec) :
		m_genotype(vec),
		m_fitnessValue(-1)
{

}

double IIndividual::fitness() const {
	if (m_fitnessValue < 0) {
		m_fitnessValue = calculateFitness();
	}
	return m_fitnessValue;
}

void IIndividual::setGene(int index, int value) {
	m_genotype[index] = value;
	m_fitnessValue = calculateFitness();
}

void IIndividual::print() {
	cout << "fitness: " << fitness()
		 << ", genotype: ["
		 << gene(0);
	for (unsigned i=1; i<m_genotype.size(); ++i) {
		cout << ", " << gene(i);
	}
	cout << "]" << endl;
}

} /* namespace EAL */

