/*
 * rational.cpp
 *
 *  Created on: 23.02.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include "rational.h"
using namespace std;

long gcd(long a, long b) {
	while (a != b)
		if (a > b)
			a -= b;
		else
			b -= a;
	return a;
}

Rational::Rational(long n, long d) : numer(n) {
	setDenominator(d);
}

/*
long Rational::getNumerator() const {
	return numer;
}

long Rational::getDenominator() const {
	return denom;
}
*/

void Rational::reduce() {
	// Rational * const this;
	if (numer == 0)
		this->denom = 1;
	else {
		long g = gcd(abs(numer), denom);
		numer /= g;
		denom /= g;
	}
	// Имаме дроб в канонична форма
}

void Rational::setDenominator(long d) {
	if (d == 0) {
		/*
		cout << "Нулев знаменател!" << endl;
		exit(1);
		*/
		cerr << "Нулев знаменател, установяване в 1!" << endl;
		denom = 1;
	} else {
		if (d < 0) {
			d = -d;
			numer = -numer;
		}
		// d > 0
		// ще съкратим дробите!
		denom = d;
		reduce();
	}
}

void Rational::print() const {
	// Rational const * const this;
	// !!! this = &s;
	// this->numer = 5;
	// cout << this->numer;
	cout << this->getNumerator() << '/' << this->getDenominator();
}

void Rational::read() {
	// Искаме да четем числата във формат <Числител>/<знаменател>
	// Разчитаме, че числото е въведено правилно
	cin >> numer;
	cin.get();
	long d;
	cin >> d;
	setDenominator(d);
}

Rational operator+(Rational const& p, Rational const& q) {
	return Rational(p.getNumerator() * q.getDenominator() +
					q.getNumerator() * p.getDenominator(),
					p.getDenominator() * q.getDenominator());
}

Rational negation(Rational p) {
	return Rational(-p.getNumerator(), p.getDenominator());
}

/*
Rational subtract(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getDenominator() -
					q.getNumerator() * p.getDenominator(),
					p.getDenominator() * q.getDenominator());
}
*/

Rational subtract(Rational p, Rational q) {
	return p + negation(q);
}

Rational multiply(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getNumerator(),
					p.getDenominator() * q.getDenominator());
}

Rational reciprocal(Rational p) {
	return Rational(p.getDenominator(), p.getNumerator());
}

Rational divide(Rational p, Rational q) {
	return multiply(p, reciprocal(q));
}

Rational::Rational(Rational const& r)
   //: numer(r.numer + 1), denom(r.denom + 1) {}
	: numer(r.numer), denom(r.denom) {
	cerr << "Копиране на Rational!\n";
}

std::ostream& operator<<(std::ostream& o, Rational const& r) {
	return o << r.getNumerator() << '/' << r.getDenominator();
}

std::istream& operator>>(std::istream& i, Rational& r) {
	/*
	char c;
	return i >> r.numer >> c >> r.denom;
	*/
	char c;
	long numer, denom;
	i >> numer >> c >> denom;
	// r = Rational(numer, denom);
	r.numer = numer;
	r.setDenominator(denom);
	return i;
}
