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
SelectFunctorFactory Population::s_selectFunFactory;

Population::Population() :
		m_size(-1)
{
	// TODO Auto-generated constructor stub
}

Population::Population(int popSize, IndividualPtr prototype, CrossFunctor::Type crossFun, MutateFunctor::Type mutateFun, SelectFunctor::Type selFun)
	: m_size(popSize)
{
	cout << "Population::Population(int popSize, IndividualPtr prototype, CrossFunctor::Type crossFun, MutateFunctor::Type mutateFun, SelectFunctor::Type selFun)" <<endl;
	m_crossFunctor = Population::s_crossFunFactory.getFunctor(crossFun);
	m_mutateFunctor = Population::s_mutateFunFactory.getFunctor(mutateFun);
	m_selectFunctor = Population::s_selectFunFactory.getFunctor(selFun);

	generateInitialIndividuals(prototype);
}

Population::~Population() {
	// TODO Auto-generated destructor stub
}

void Population::generateInitialIndividuals(const IndividualPtr prototype) {
	IndividualPtr individual;
	for (int i=0; i<m_size; ++i) {
		individual = prototype->makeRandomClone();
		// TODO if (!individual->isValid()) throw
		m_individuals.push_back(individual);
	}

	m_individuals.sort(IIndividual::rcomp);
//	for (IndividualPtr ind : m_individuals) cout<<ind->gene(0)<<endl;
	m_theBestOne = (*m_individuals.begin());
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

IndividualPtr Population::selectOne() const {
	if (!m_selectFunctor) {
		cout << "[ERROR] Populate::selectOne() - "
			 << "m_selectFunctor is empty!";
		return IndividualPtr();
	}
	return (*m_selectFunctor)(m_individuals);
}

void Population::add(std::list<IndividualPtr> &individuals) {
	individuals.sort(IIndividual::rcomp);
	m_individuals.merge(individuals, IIndividual::rcomp);
	m_theBestOne = (*m_individuals.begin());
}

void Population::print() {
	cout << "Population:";
	for (IndividualPtr ind : m_individuals) {
		cout << " " << ind->fitness();
	}
	cout<<endl;
}

} /* namespace EAL */
