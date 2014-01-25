/*
 * MutateFunctorFactory.h
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#ifndef MUTATEFUNCTORFACTORY_H_
#define MUTATEFUNCTORFACTORY_H_

#include <map>
#include <memory>
#include "MutateFunctor.h"

namespace EAL {

class MutateFunctorFactory {
public:
	MutateFunctorFactory();
	virtual ~MutateFunctorFactory();
	std::shared_ptr<MutateFunctor> getFunctor(MutateFunctor::Type type);
private:
	std::map<MutateFunctor::Type, std::shared_ptr<MutateFunctor> > m_functorMap;
};

} /* namespace EAL */

#endif /* MUTATEFUNCTORFACTORY_H_ */
