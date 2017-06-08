/*
 * json_serializable.cpp
 *
 *  Created on: 8.06.2017 г.
 *      Author: trifon
 */

#include "json_serializable.h"

void JSONSerializable::startSerialize(std::ostream& os) const {
	os << "{\n";
	serializeType(os);
}


void JSONSerializable::finishSerialize(std::ostream& os) const {
	os << "}\n";
}


void JSONSerializable::serializeString(std::ostream& os, const char* s) const {
	os << '"' << s << '"';
}


void JSONSerializable::serializeInt(std::ostream& os, int n) const {
	os << n;
}


void JSONSerializable::serializeKey(std::ostream& os, const char* key) const {
	serializeString(os, key);
	os << " : ";
}

void JSONSerializable::serializeKeyIntValue(std::ostream& os, const char* key,
		int value) const {
	serializeKey(os, key);
	serializeInt(os, value);
	os << ",\n";
}

void JSONSerializable::serializeKeyStringValue(std::ostream& os,
		const char* key, const char* value) const {
	serializeKey(os, key);
	serializeString(os, value);
	os << ",\n";
}

void JSONSerializable::serializeType(std::ostream& os) const {
	serializeKeyStringValue(os, KEY_TYPE, getType());
}
