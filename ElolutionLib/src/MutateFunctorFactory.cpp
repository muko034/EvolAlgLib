/*
 * MutateFunctorFactory.cpp
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#include "MutateFunctorFactory.h"
#include "SimpleMutationFunctor.h"

using namespace std;

namespace EAL {

MutateFunctorFactory::MutateFunctorFactory() {
	m_functorMap[MutateFunctor::Type::SIMPLE] = shared_ptr<MutateFunctor>(new SimpleMutationFunctor());
}

MutateFunctorFactory::~MutateFunctorFactory() {
	// TODO Auto-generated destructor stub
}

shared_ptr<MutateFunctor> MutateFunctorFactory::getFunctor(MutateFunctor::Type type) {
	return m_functorMap[type];
}

} /* namespace EAL */

