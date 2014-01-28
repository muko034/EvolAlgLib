/*
 * RankSelectFunctor.h
 *
 *  Created on: 28-01-2014
 *      Author: kuba
 */

#ifndef RANKSELECTFUNCTOR_H_
#define RANKSELECTFUNCTOR_H_

#include "SelectFunctor.h"
#include "IIndividual.h"

namespace EAL {

class RankSelectFunctor: public EAL::SelectFunctor {
public:
	RankSelectFunctor() {}
	virtual ~RankSelectFunctor() {}
	virtual IndividualPtr operator()(std::list<IndividualPtr> individuals) const;
};

} /* namespace EAL */
#endif /* RANKSELECTFUNCTOR_H_ */
