/*
 * RouletteSelectFunctor.h
 *
 *  Created on: 26-01-2014
 *      Author: kuba
 */

#ifndef ROULETTESELECTFUNCTOR_H_
#define ROULETTESELECTFUNCTOR_H_

#include "SelectFunctor.h"
#include "IIndividual.h"
#include <random>

namespace EAL {

class RouletteSelectFunctor: public EAL::SelectFunctor {
public:
	RouletteSelectFunctor();
	virtual ~RouletteSelectFunctor();
	virtual IndividualPtr operator()(std::list<IndividualPtr> individuals) const;
private:
//	std::random_device m_rd;
//	std::default_random_engine m_randomEngine;
};

} /* namespace EAL */
#endif /* ROULETTESELECTFUNCTOR_H_ */
