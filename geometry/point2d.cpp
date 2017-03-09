/*
 * point2d.cpp
 *
 *  Created on: 2.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
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

// търси разстоянието между *this и p
double Point2D::distance(Point2D p) const {
	/*
	 *
	 return sqrt(pow(p.getX() - getX(), 2) +
			    pow(p.getY() - getY(), 2));
			    */
	p.reflectOrigin();
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

void Point2D::reflectOrigin() {
	setX(-getX());
	setY(-getY());
}

void Point2D::print() const {
	std::cout << '(' << getX() << ','
			         << getY() << ')';
}

// във формат (x,y)
// считаме, че входът е коректен
void Point2D::read() {
	char c;
	// прескачаме (
	std::cin >> c;
	std::cin >> x;
	// прескачаме ,
	std::cin >> c;
	std::cin >> y;
	// прескачаме )
	std::cin >> c;
}
