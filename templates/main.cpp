/*
 * main.cpp
 *
 *  Created on: 27.04.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include "../rational/rational.h"
#include "../geometry/point2d.h"

template <typename T>
void swap(T& a, T& b) {
	T tmp = a; a = b; b = tmp;
}

template <typename T>
void reverse(T* a, int n) {
	for(int i = 0; i < n/2; i++)
		swap<T>(a[i], a[n-i-1]);
}

template <typename T>
void printArray(T* a, int n) {
	for(int i = 0; i < n; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;
}

void printArray(Point2D* a, int n) {
	for(int i = 0; i < n; i++) {
		a[i].print();
		std::cout << ' ';
	}
	std::cout << std::endl;
}

bool operator==(Rational const& p, Rational const& q) {
	return p.getNumerator() == q.getNumerator() &&
		   p.getDenominator() == q.getDenominator();
}

template <typename T>
int countOccurrences(T* a, int n, T const& x) {
	int count = 0;
	for(int i = 0; i < n; i++)
		if (a[i] == x)
			count++;
	return count;
}

void testTemplates() {
	Rational p(1, 2), q(3, 4);
	swap<Rational>(p, q);
	Rational a[] = { 1, 5, Rational(2, 3),
					Rational(5, 8) };
	printArray(a, 4);
	reverse<Rational>(a, 4);
	printArray(a, 4);
	int b[] = { 1, 2, 3, 4 };
	printArray(b, 4);
	reverse(b, 4);
	printArray(b, 4);
	Point2D c[] = { Point2D(1, 1),
			Point2D(2, 2),
			Point2D(3, 3),
			Point2D(4, 4) };
	/// !!! printArray<Point2D>(c, 4);
	printArray(c, 4);
	std::cout << countOccurrences(a, 4, Rational(2, 3))
			  << std::endl;
	std::cout << countOccurrences(b, 4, 2)
			  << std::endl;
	/* !!!
	std::cout << countOccurrences(c, 4, Point2D(2, 3))
			  << std::endl;
			  */

}

int main() {
	testTemplates();
	return 0;
}



