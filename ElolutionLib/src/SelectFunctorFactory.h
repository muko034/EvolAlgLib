/*
 * SelectFunctorFactory.h
 *
 *  Created on: 26-01-2014
 *      Author: kuba
 */

#ifndef SELECTFUNCTORFACTORY_H_
#define SELECTFUNCTORFACTORY_H_

#include <map>
#include <memory>
#include "SelectFunctor.h"

namespace EAL {

class SelectFunctorFactory {
public:
	SelectFunctorFactory();
	virtual ~SelectFunctorFactory();
	std::shared_ptr<SelectFunctor> getFunctor(SelectFunctor::Type type);
private:
	std::map<SelectFunctor::Type, std::shared_ptr<SelectFunctor> > m_functorMap;
};

} /* namespace EAL */
#endif /* SELECTFUNCTORFACTORY_H_ */
