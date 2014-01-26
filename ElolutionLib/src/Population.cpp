/*
 * Populate.cpp
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#include "Population.h"
#include <iostream>
#include <random>

using namespace std;

namespace EAL {

CrossFunctorFactory Population::s_crossFunFactory;
MutateFunctorFactory Population::s_mutateFunFactory;

Population::Population() :
		m_size(-1)
{
	// TODO Auto-generated constructor stub
}

Population::Population(int popSize, IndividualPtr prototype, CrossFunctor::Type crossFun, MutateFunctor::Type mutateFun)
	: m_size(popSize)
{
	m_crossFunctor = Population::s_crossFunFactory.getFunctor(crossFun);
	m_mutateFunctor = Population::s_mutateFunFactory.getFunctor(mutateFun);

	generateInitialIndividuals(prototype);
}

Population::~Population() {
	// TODO Auto-generated destructor stub
}

void Population::generateInitialIndividuals(const IndividualPtr prototype) {
	// Seed with a real random value, if available
	random_device rd;
	default_random_engine e1(rd());
	uniform_int_distribution<int> uniform_dist(prototype->minValue(), prototype->maxValue());

	IndividualPtr individual;
	for (int i=0; i<m_size; ++i) {
		individual = prototype->clone();
		do {
			for (int i=0; i<individual->genesNo(); ++i) {
					individual->setGene(i, uniform_dist(e1));
			}
		} while (!individual->isValid());
		m_individuals.push_back(individual);
	}
}

IndividualPtr Population::crossover(const IndividualPtr mommy, const IndividualPtr daddy) {
	if (!m_crossFunctor) {
		cout << "[ERROR] Populate::crossover(const IndividualPtr, const IndividualPtr) - "
			 << "m_crossFunctor is empty!";
		return IndividualPtr();
	}
	return (*m_crossFunctor)(mommy, daddy);
}

void Population::mutate(IndividualPtr individual) {
	if (!m_mutateFunctor) {
		cout << "[ERROR] Populate::mutate() - "
			 << "m_mutateFunctor is empty!";
		return;
	}
	(*m_mutateFunctor)(individual);
}

} /* namespace EAL */
