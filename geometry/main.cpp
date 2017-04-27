/*
 * main.cpp
 *
 *  Created on: 2.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;
#include "point2d.cpp"
#include "point3d.h"

void testPoint2D() {
	Point2DD p;
	Point2DD q(3, 4), r(7, 7);
	cout << p.radius() << ' ' << q.radius() << endl;
	cout << p.distance(q) << endl;
	cout << q.distance(r) << endl;
	q.translate(r);
	q.print();cout << endl;
	q.read();
	r.read();
	cout << q.distance(r) << endl;
}

void testPoint3D() {
	Point3D p;
	Point3D q(3, 4, 12);
	cout << q.radius() << endl;
	Point3D r(15, 7, 16);
	cout << q.distance(r) << endl;
}

int main() {
	// testPoint2D();
	testPoint3D();
}

