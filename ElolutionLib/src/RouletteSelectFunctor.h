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

namespace EAL {

class RouletteSelectFunctor: public EAL::SelectFunctor {
public:
	RouletteSelectFunctor() {}
	virtual ~RouletteSelectFunctor() {}
	virtual IndividualPtr operator()(std::list<IndividualPtr> individuals) const;
};

} /* namespace EAL */
#endif /* ROULETTESELECTFUNCTOR_H_ */
