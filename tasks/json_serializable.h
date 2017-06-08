/*
 * json_serializable.h
 *
 *  Created on: 8.06.2017 г.
 *      Author: trifon
 */

#ifndef JSON_SERIALIZABLE_H_
#define JSON_SERIALIZABLE_H_

#include "serializable.h"

class JSONSerializable : public Serializable {
public:

	void startSerialize(std::ostream&) const;
	void finishSerialize(std::ostream&) const;

	void serializeString(std::ostream&, char const*) const;
	void serializeInt(std::ostream&, int) const;
	void serializeKey(std::ostream&, char const*) const;
	void serializeKeyIntValue(std::ostream&,
			                  char const*, int) const;
	void serializeKeyStringValue(std::ostream&,
			                  char const*, char const*) const;

};



#endif /* JSON_SERIALIZABLE_H_ */
