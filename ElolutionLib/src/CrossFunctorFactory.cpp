/*
 * CrossFunctorFactory.cpp
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#include "CrossFunctorFactory.h"

using namespace std;

namespace EAL {

CrossFunctorFactory::CrossFunctorFactory() {
	// TODO Auto-generated constructor stub

}

CrossFunctorFactory::~CrossFunctorFactory() {
	// TODO Auto-generated destructor stub
}

shared_ptr<CrossFunctor> CrossFunctorFactory::getFunctor(CrossFunctor::Type type) {
	return m_functorMap[type];
}

} /* namespace EAL */

