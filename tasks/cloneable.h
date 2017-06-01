/*
 * cloneable.h
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#ifndef CLONEABLE_H_
#define CLONEABLE_H_

class Cloneable {
public:
	virtual Cloneable* clone() const = 0;
};



#endif /* CLONEABLE_H_ */
