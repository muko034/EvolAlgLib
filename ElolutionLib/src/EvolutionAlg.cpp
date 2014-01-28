/*
 * EvolutionAlg.cpp
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#include "EvolutionAlg.h"
#include <list>
#include <random>
#include <iostream>

using namespace std;

namespace EAL {

EvolutionAlg::EvolutionAlg(Population population, int maxIterations, Mode mode) :
		m_population(population),
		m_maxIterations(maxIterations),
		m_currIteration(0),
		m_stop(false),
		m_mode(mode)
{
}

EvolutionAlg::~EvolutionAlg() {
	// TODO Auto-generated destructor stub
}

void EvolutionAlg::start() {
	IndividualPtr mommy, daddy, child;
	list<IndividualPtr> newGeneration;
	while (!m_stop) {
		if (m_mode == Mode::LOUD) {
			cout << m_currIteration << ".\t";
			m_population.print();
		}
		++m_currIteration;
		for (int i=0; i<2*m_population.size(); ++i) {
			selection(mommy, daddy);
			child = crossing(mommy, daddy);
			mutation(child);
			newGeneration.push_back(child);
		}
		m_population.add(newGeneration);
		killWorst();
		newGeneration.clear();
		if (stopCondition()) m_stop = true;
	}
}

void EvolutionAlg::killWorst() {
	m_population.m_individuals.resize(m_population.size());
}

void EvolutionAlg::mutation(IndividualPtr &ind) {
	random_device rd;
	default_random_engine gen(rd());
	uniform_real_distribution<double> dis(0.0, 1.0);
	double random = dis(gen);

	if (random <= m_population.m_mutationChange) {
		m_population.mutate(ind);
	}
}

} /* namespace EAL */
