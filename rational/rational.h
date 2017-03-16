/*
 * rational.h
 *
 *  Created on: 23.02.2017 г.
 *      Author: trifon
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

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
	Rational(long numer = 1, long denom = 0);

	// конструктор с параметри
	Rational(long numer, long denom);

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

};

inline double Rational::toDouble() const {
	return (double)getNumerator() / getDenominator();
}

Rational add(Rational p, Rational q);

Rational negation(Rational p);

Rational subtract(Rational p, Rational q);

Rational multiply(Rational p, Rational q);

Rational reciprocal(Rational p);

Rational divide(Rational p, Rational q);


#endif /* RATIONAL_H_ */
