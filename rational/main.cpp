/*
 * main.cpp
 *
 *  Created on: 23.02.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include <cmath>
using namespace std;
#include "rational.h"

long fact(int n) {
	return n == 0 ? 1 : n * fact(n - 1);
}

Rational myexp(int k, int n) {
	Rational sum;
	for(int i = 0; i <= n; i++)
		sum = add(sum,Rational(pow(k, i),fact(i)));
	return sum;
}

int main() {
	Rational r;
	// Rational s = { 1, 2 };
	Rational s(1, 2);
	// !!! cout << s.numer << '/' << s.denom << endl;
	cout << s.getNumerator() << '/' << s.getDenominator() << endl;
	s.print();
	cout << s.toDouble() << endl;
	s.read();
	s.print();
	cout << s.toDouble() << endl;

	add(s, Rational(1, 2)).print();
	subtract(s, Rational(1, 2)).print();
	multiply(s, Rational(1, 2)).print();
	divide(s, Rational(1, 2)).print();
	divide(s, r).print();
	Rational(5, 0).print();
	// !!! s.denom = 0;

	Rational er = myexp(1, 10);
	er.print();
	cout << er.toDouble() << endl;
	// !!! er.numer = 5;


	return 0;
}


