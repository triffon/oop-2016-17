/*
 * main.cpp
 *
 *  Created on: 23.02.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include <cmath>
// using namespace std;
#include "rational.h"
#include "rational.h"
#include "rational_point.h"

/*
 * !!!
class Rational {
	int numer, denom;
	// ...
};
*/

long fact(int n) {
	return n == 0 ? 1 : n * fact(n - 1);
}

Rational myexp(int k, int n) {
	Rational sum;
	for(int i = 0; i <= n; i++)
		sum = sum + Rational(pow(k, i),fact(i));
	return sum;
}

const int endl = 10;

void testRational() {
	Rational r;
	// Rational s = { 1, 2 };
	Rational s(1, 2);
	// Rational s = Rational(1, 2);
	// !!! cout << s.numer << '/' << s.denom << endl;
	// std::cout << s->numer << '/' << s->denom << std::endl;
	std::cout << s.getNumerator() << '/' << s.getDenominator() << std::endl;
	s.print();
	std::cout << s.toDouble() << std::endl;
	s.read();
	s.print();
	std::cout << s.toDouble() << std::endl;

	(s + Rational(1, 2)).print();
	subtract(s, Rational(1, 2)).print();
	multiply(s, Rational(1, 2)).print();
	divide(s, Rational(1, 2)).print();
	divide(s, r).print();
	Rational(5, 0).print();
	// !!! s.denom = 0;

	Rational er = myexp(1, 10);
	er.print();
	std::cout << er.toDouble() << std::endl;
	// !!! er.numer = 5;

	// Не е препоръчително
	// !!! class A { int a; public: int getA() const; } objectA;

	Rational* ps = &s;
	// !!! *ps.print();
	// !!! *(ps.print());
	(*ps).print();
	ps->print();
	s.toDouble();
	ps->toDouble();

	// !!! s.reduce();
	// !!! ps->reduce();

	int endl = 5;
	std::cout << s.getNumerator() << endl;
	std::cout << s.getNumerator() << ::endl;
	std::cout << s.getNumerator() << std::endl;
}

Rational addOne(Rational r) {
	return Rational(1) + r;// r + 1;
}

void testCopy() {
	Rational r(2, 3);
	r.print();
	// Rational p(r);
	// Rational p = Rational(r);
	Rational p = r;
	p.print();
	addOne(p).print();
}

void testRationalPoint() {
	RationalPoint rp;
	rp.print();
	RationalPoint rp2(7, Rational(5, 3));
	rp2.print();
	RationalPoint rp3 = rp2;
	rp3.print();
}

void testArrays() {
	Rational *ar = new Rational[5];
	for(int i = 0; i < 5; i++) {
		ar[i].print();
		std::cout << std::endl;
	}
	delete ar;
}

void testConvert() {
	Rational r(9, 4);
	Rational q = 3;
	int x = r;
	std::cout << x << std::endl;
	std::cout << sqrt(r) << std::endl;
}

int main() {
	// testRational();
	// testCopy();
	// testRationalPoint();
	// testArrays();
	testConvert();
	return 0;

}


