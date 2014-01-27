/*
 * EvolutionAlg.cpp
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#include "EvolutionAlg.h"
#include <list>
#include <iostream>

using namespace std;

namespace EAL {

EvolutionAlg::EvolutionAlg() {
	// TODO Auto-generated constructor stub

}

EvolutionAlg::EvolutionAlg(Population population, int maxIterations) :
		m_population(population),
		m_maxIterations(maxIterations),
		m_stop(false)
{
}

EvolutionAlg::~EvolutionAlg() {
	// TODO Auto-generated destructor stub
}

void EvolutionAlg::start() {
	IndividualPtr mommy, daddy, child;
	list<IndividualPtr> newGeneration;
	int count = m_maxIterations;
	while (!m_stop) {
		m_population.print();
		for (int i=0; i<2*m_population.size(); ++i) {
			mommy = selectOne();
			daddy = selectOne();
			child = m_population.crossover(mommy, daddy);
			m_population.mutate(child);
			newGeneration.push_back(child);
		}
		m_population.add(newGeneration);
		killWorst();
		newGeneration.clear();
		if (--count == 0) m_stop = true;
		cout << "The best one: " << m_population.m_theBestOne->fitness() << endl;
	}
}

void EvolutionAlg::killWorst() {
	m_population.m_individuals.resize(m_population.size());
}

} /* namespace EAL */
