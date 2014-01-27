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

	void setPopulation(const Population &population) { m_population = population; }

protected:
	void killWorst();

private:
	Population m_population;
	int m_maxIterations;
	bool m_stop;
};

} /* namespace EAL */
#endif /* EVOLUTIONALG_H_ */
