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

IIndividual::IIndividual(int genesNo, int minValue, int maxValue) :
		m_minValue(minValue),
		m_maxValue(maxValue)
{
	for (int i=0; i<genesNo; ++i) m_genotype.push_back(0);

}

IIndividual::~IIndividual() {
	// TODO Auto-generated destructor stub
}

//IndividualPtr IIndividual::crossover(const IIndividual &other) const {
//	if (!m_crossFunctor) {
//		cout << "[ERROR] IIndividual::crossover(const IIndividual &other) - "
//			 << "m_mutateFunctor is empty!";
//		return IndividualPtr();
//	}
//	return (*m_crossFunctor)( other );
//}

//void IIndividual::mutate() {
//	if (!m_mutateFunctor) {
//		cout << "[ERROR] IIndividual::mutate() - "
//			 << "m_mutateFunctor is empty!";
//		return;
//	}
//	(*m_mutateFunctor)();
//}

IndividualPtr IIndividual::clone() {
	// TODO
}

} /* namespace EAL */

