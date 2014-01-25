/*
 * IIndividual.cpp
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#include "IIndividual.h"
#include <iostream>

using namespace std;

namespace EAL {

IIndividual::IIndividual() {
	// TODO Auto-generated constructor stub
}

IIndividual::IIndividual(CrossFunctor::Type crossFun, MutateFunctor::Type mutateFun) {
	m_crossFunctor = IIndividual::m_crossFunFactory.getFunctor(crossFun);
	m_mutateFunctor = IIndividual::m_mutateFunFactory.getFunctor(mutateFun);
}

IIndividual::~IIndividual() {
	// TODO Auto-generated destructor stub
}

IndividualPtr IIndividual::crossover(const IIndividual &other) const {
	if (!m_crossFunctor) {
		cout << "[ERROR] IIndividual::crossover(const IIndividual &other) - "
			 << "m_mutateFunctor is empty!";
		return IndividualPtr();
	}
	return (*m_crossFunctor)( other );
}

void IIndividual::mutate() {
	if (!m_mutateFunctor) {
		cout << "[ERROR] IIndividual::mutate() - "
			 << "m_mutateFunctor is empty!";
		return;
	}
	(*m_mutateFunctor)();
}

} /* namespace EAL */

