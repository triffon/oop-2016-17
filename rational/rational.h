/*
 * rational.h
 *
 *  Created on: 23.02.2017 г.
 *      Author: trifon
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <iostream>

class Rational {
private:

	/* Член-данни */
	long numer; // числител
	long denom; // знаменател

	/* Служебни член-функции */

	// съкращава рационалното число
	void reduce();

public:

	/** Конструктори **/

	// Комбиниран конструктор по подразбиране и с параметри
	Rational(long numer = 0, long denom = 1);

	// Конструктор за копиране
	Rational(Rational const& r);

	/** Селектори **/

	// селектор за числителя
	long getNumerator() const {
		return numer;
	}

	// селектор за знаменателя
	long getDenominator() const {
		return denom;
	}

	// извеждане
	void print() const;

	// селектор за преобразуване до число с плаваща запетая
	double toDouble() const;

	/** Мутатори **/

	// мутатор за знаменателя
	void setDenominator(long d);

	// мутатор за въвеждане от клавиатурата
	void read();

	friend std::istream& operator>>(std::istream& i, Rational& r);

};

inline double Rational::toDouble() const {
	return (double)getNumerator() / getDenominator();
}

Rational operator+(Rational const& p, Rational const& q);

Rational negation(Rational p);

Rational subtract(Rational p, Rational q);

Rational multiply(Rational p, Rational q);

Rational reciprocal(Rational p);

Rational divide(Rational p, Rational q);

std::ostream& operator<<(std::ostream& o, Rational const& r);


#endif /* RATIONAL_H_ */
