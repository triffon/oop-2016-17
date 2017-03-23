/*
 * rational_point.h
 *
 *  Created on: 23.03.2017 г.
 *      Author: trifon
 */

#ifndef RATIONAL_POINT_H_
#define RATIONAL_POINT_H_

#include <iostream>
#include "rational.h"

class RationalPoint {
private:
	Rational x, y;

public:
	RationalPoint(Rational const& a = Rational(),
				  Rational const& b = Rational()) :
		x(a), y(b) {}

	RationalPoint(RationalPoint const& rp) : x(rp.x), y(rp.y) {
		std::cerr << "Копиране на RationalPoint\n";
	}

	Rational getX() const { return x; }
	Rational getY() const { return y; }

	void print() const {
		std::cout << '(';
		getX().print();
		std::cout << ',';
		getY().print();
		std::cout << ')';
	}
};



#endif /* RATIONAL_POINT_H_ */
