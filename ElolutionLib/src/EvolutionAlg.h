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
	EvolutionAlg(int maxIterations);
	virtual ~EvolutionAlg();

	void start();

	void setPopulation(const Population &population) { m_population = population; }

private:
	Population m_population;
	int m_maxIterations;
	bool m_stop;
};

} /* namespace EAL */
#endif /* EVOLUTIONALG_H_ */
