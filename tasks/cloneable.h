/*
 * cloneable.h
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#ifndef CLONEABLE_H_
#define CLONEABLE_H_

template <typename T>
class Cloneable {
public:
	virtual T* clone() const = 0;
	virtual ~Cloneable() {}
};



#endif /* CLONEABLE_H_ */
