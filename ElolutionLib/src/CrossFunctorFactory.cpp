/*
 * CrossFunctorFactory.cpp
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#include "CrossFunctorFactory.h"
#include "AverageCrossFunctor.h"

using namespace std;

namespace EAL {

CrossFunctorFactory::CrossFunctorFactory() {
	m_functorMap[CrossFunctor::Type::AVERAGE] = shared_ptr<CrossFunctor>(new AverageCrossFunctor());
}

CrossFunctorFactory::~CrossFunctorFactory() {
	// TODO Auto-generated destructor stub
}

shared_ptr<CrossFunctor> CrossFunctorFactory::getFunctor(CrossFunctor::Type type) {
	return m_functorMap[type];
}

} /* namespace EAL */

