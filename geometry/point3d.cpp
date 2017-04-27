/*
 * point3d.cpp
 *
 *  Created on: 9.03.2017 г.
 *      Author: trifon
 */

#include "point3d.h"

Point3D::Point3D() {
	// p.setX(0);
	// p.setY(0);
	// Ще се извика конструкторът Point2D()
	z = 0;
}

Point3D::Point3D(Point2DD const& p, double z) {
	this->p = p;
	setZ(z);
}

Point3D::Point3D(double x, double y, double z) {
	setX(x);
	setY(y);
	setZ(z);
}

double Point3D::radius() const {
	Point2DD q(p.radius(), z);
	return q.radius();
// 	return Point2D(p.radius(), z).radius();
}

double Point3D::distance(Point3D p) const {
	p.reflectOrigin();
	p.translate(*this);
	return p.radius();
}

void Point3D::reflectOrigin() {
	p.reflectOrigin();
	setZ(-getZ());
}

void Point3D::translateZ(double dz) {
	setZ(getZ() + dz);
	// z += dz;
}

void Point3D::translateX(double dx) {
	// setX(getX() + dx);
	p.translateX(dx);
}

void Point3D::translateY(double dy) {
	// setY(getY() + dy);
	p.translateY(dy);
}

void Point3D::translate(Point3D const& v) {
	p.translate(v.p);
	translateZ(v.getZ());
}



