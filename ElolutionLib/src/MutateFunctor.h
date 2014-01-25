/*
 * MutateFunctor.h
 *
 *  Created on: 25-01-2014
 *      Author: kuba
 */

#ifndef MUTATEFUNCTOR_H_
#define MUTATEFUNCTOR_H_

namespace EAL {

class MutateFunctor {
public:

	enum Type {
			SOME = 0
		};

	MutateFunctor();
	virtual ~MutateFunctor();
	virtual void operator()() =0;
};

} /* namespace EAL */

#endif /* MUTATEFUNCTOR_H_ */
