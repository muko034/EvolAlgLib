/*
 * EvolutionAlg.h
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#ifndef EVOLUTIONALG_H_
#define EVOLUTIONALG_H_

#include "Population.h"

namespace EAL {

class EvolutionAlg {
public:
	EvolutionAlg();
	EvolutionAlg(Population population, int maxIterations);
	virtual ~EvolutionAlg();

	IndividualPtr selectOne() { return m_population.selectOne(); }
	void start();
	virtual bool stopCondition() { return m_currIteration == m_maxIterations; }

	void setPopulation(const Population &population) { m_population = population; }
	int maxIteration() const { return m_maxIterations; }
	int currIteration() const { return m_currIteration; }

protected:
	void killWorst();

private:
	Population m_population;
	int m_maxIterations;
	int m_currIteration;
	bool m_stop;
};

} /* namespace EAL */
#endif /* EVOLUTIONALG_H_ */
