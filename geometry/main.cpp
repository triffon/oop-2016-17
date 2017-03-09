/*
 * main.cpp
 *
 *  Created on: 2.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;
#include "point2d.h"

int main() {
	Point2D p;
	Point2D q(3, 4), r(7, 7);
	cout << p.radius() << ' ' << q.radius() << endl;
	cout << p.distance(q) << endl;
	cout << q.distance(r) << endl;
	q.translate(r);
	q.print();cout << endl;
	q.read();
	r.read();
	cout << q.distance(r) << endl;
	return 0;
}


