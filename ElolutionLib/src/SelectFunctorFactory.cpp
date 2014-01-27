/*
 * SelectFunctorFactory.cpp
 *
 *  Created on: 26-01-2014
 *      Author: kuba
 */

#include "SelectFunctorFactory.h"
#include "RouletteSelectFunctor.h"

using namespace std;

namespace EAL {

SelectFunctorFactory::SelectFunctorFactory() {
	m_functorMap[SelectFunctor::Type::ROULETTE] = shared_ptr<SelectFunctor>(new RouletteSelectFunctor());

}

SelectFunctorFactory::~SelectFunctorFactory() {
	// TODO Auto-generated destructor stub
}

shared_ptr<SelectFunctor> SelectFunctorFactory::getFunctor(SelectFunctor::Type type) {
	return m_functorMap[type];
}

} /* namespace EAL */
