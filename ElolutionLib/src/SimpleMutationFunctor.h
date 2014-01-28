/*
 * SimpleMutationFunctor.h
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#ifndef SIMPLEMUTATIONFUNCTOR_H_
#define SIMPLEMUTATIONFUNCTOR_H_

#include "MutateFunctor.h"
#include "IIndividual.h"

namespace EAL {

class SimpleMutationFunctor: public EAL::MutateFunctor {
public:
	SimpleMutationFunctor(double mean = 0.0, double stddev = 1.0) : m_mean(mean), m_stddev(stddev) {}
	virtual ~SimpleMutationFunctor() {}
	virtual void operator()(IndividualPtr individual);
private:
	double m_mean;
	double m_stddev;
};

} /* namespace EAL */
#endif /* SIMPLEMUTATIONFUNCTOR_H_ */
