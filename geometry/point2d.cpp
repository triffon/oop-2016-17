/*
 * point2d.cpp
 *
 *  Created on: 2.03.2017 г.
 *      Author: trifon
 */

#include <cmath>
#include "point2d.h"

Point2D::Point2D() {
	x = y = 0;
}

Point2D::Point2D(double x, double y) {
	this->x = x;
	this->y = y;
}

double Point2D::radius() const {
	return sqrt(getX() * getX()
				+
				getY() * getY());
}

double Point2D::distance(Point2D p) const {
	/*
	 *
	 return sqrt(pow(p.getX() - getX(), 2) +
			    pow(p.getY() - getY(), 2));
			    */
	p.translate(*this);
	return p.radius();
}

void Point2D::translate(Point2D const& v) {
	translateX(v.getX());
	translateY(v.getY());
}

void Point2D::translateX(double dx) {
	x += dx;
}

void Point2D::translateY(double dy) {
	y += dy;
}
