/*
 * point3d.h
 *
 *  Created on: 9.03.2017 г.
 *      Author: trifon
 */

#ifndef POINT3D_H_
#define POINT3D_H_

#include "point2d.cpp"

class Point3D {
private:
	Point2DD p; // проекция на точката в Oxy
	double z;  // разстояние на точката до Oxy

public:

	/** Конструктори **/

	// конструктор по подразбиране
	Point3D();

	// конструктори с параметри
	Point3D(Point2DD const& p, double z);
	Point3D(double x, double y, double z);

	/** Селектори **/

	// Селектори за координати
	double getX() const { return p.getX(); }
	double getY() const { return p.getY(); }
	double getZ() const { return z; }

	// Разстояние от началото на координатната система
	double radius() const;

	// Разстояние до друга точка
	double distance(Point3D p) const;

	// В кой октант е точката
	// Връща число от 1 до 8, в зависимост от октанта
	// Връща 0, ако е началото на координатната система
	// за домашно
	// как да засичаме дали сме на осите/координатните равнини?
	short octant() const;

	// извеждане
	// домашно
	void print() const;

	/** Мутатори **/

	// Транслация по x, y и Z
	void translateX(double dx);
	void translateY(double dy);
	void translateZ(double dz);
	void translate(Point3D const& v);

	// Въвеждане
	// домашно
	void read();

	// симетрия относно началото на координатната система
	void reflectOrigin();

	// установяване на координати
	void setX(double x) { p.setX(x); }
	void setY(double y) { p.setY(y); }
	void setZ(double z) { this->z = z; }
};



#endif /* POINT3D_H_ */
