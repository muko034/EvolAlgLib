/*
 * CrossFunctorFactory.h
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#ifndef CROSSFUNCTORFACTORY_H_
#define CROSSFUNCTORFACTORY_H_

#include <map>
#include <memory>
#include "CrossFunctor.h"

namespace EAL {

class CrossFunctorFactory {
public:
	CrossFunctorFactory();
	virtual ~CrossFunctorFactory();
	std::shared_ptr<CrossFunctor> getFunctor(CrossFunctor::Type type);
private:
	std::map<CrossFunctor::Type, std::shared_ptr<CrossFunctor> > m_functorMap;
};

} /* namespace EAL */

#endif /* CROSSFUNCTORFACTORY_H_ */
