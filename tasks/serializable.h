/*
 * serializable.h
 *
 *  Created on: 8.06.2017 г.
 *      Author: trifon
 */

#ifndef SERIALIZABLE_H_
#define SERIALIZABLE_H_

#include <iostream>

class Serializable {
public:
	virtual bool serialize(std::ostream&) const = 0;
	virtual bool deserialize(std::istream&) = 0;
	virtual ~Serializable() {}
};



#endif /* SERIALIZABLE_H_ */
