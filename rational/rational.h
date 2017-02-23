/*
 * rational.h
 *
 *  Created on: 23.02.2017 г.
 *      Author: trifon
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

class Rational {
// private:
	long numer; // числител
	long denom; // знаменател

	void reduce();

public:
	Rational();

	Rational(long n, long d);

	long getNumerator();

	long getDenominator();

	void setDenominator(long d);

	void print();

	double toDouble();

	void read();

};

Rational add(Rational p, Rational q);

Rational negation(Rational p);

Rational subtract(Rational p, Rational q);

Rational multiply(Rational p, Rational q);

Rational reciprocal(Rational p);

Rational divide(Rational p, Rational q);


#endif /* RATIONAL_H_ */
