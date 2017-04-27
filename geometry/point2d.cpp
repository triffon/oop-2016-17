/*
 * point2d.cpp
 *
 *  Created on: 2.03.2017 г.
 *      Author: trifon
 */

/*
 * point2d.h
 *
 *  Created on: 2.03.2017 г.
 *      Author: trifon
 */

#ifndef POINT2D_CPP_
#define POINT2D_CPP_

#include <iostream>
#include <cmath>


// Точка в равнината
template <typename T>
class Point2D {
private:
	T x, y; // координатите на точката

public:

	/** Конструктори **/

	// конструктор по подразбиране
	Point2D();

	// конструктор с параметри
	Point2D(T const& x, T const& y);

	/** Селектори **/

	// Селектори за координати
	T getX() const { return x; }
	T getY() const { return y; }

	// Разстояние от началото на координатната система
	double radius() const;

	// Разстояние до друга точка
	double distance(Point2D p) const;

	// В кой квадрант е точката
	// Връща число от 1 до 4, в зависимост от квадранта
	// Връща отрицателно число от -1 до -4, ако лежи на някоя от осите
	// указва от коя страна на осите е
	// Връща 0, ако е началото на координатната система
	// за домашно
	short quadrant() const;

	// извеждане
	void print() const;

	/** Мутатори **/

	// Транслация по x и y
	void translateX(T const& dx);
	void translateY(T const& dy);
	void translate(Point2D const& v);

	// Въвеждане
	void read();

	// симетрия относно x == y
	// за домашно
	void reflect();

	// симетрия относно началото на координатната система
	void reflectOrigin();

	// установяване на координати
	void setX(T const& x) { this->x = x; }
	void setY(T const& y) { this->y = y; }

	// ротация относно origin с ъгъл angle
	// за домашно
	void rotate(Point2D const& origin, double angle);
};

typedef Point2D<double> Point2DD;

template <typename T>
Point2D<T>::Point2D() {
	x = y = 0;
}

template <typename T>
Point2D<T>::Point2D(T const& x, T const& y) {
	this->x = x;
	this->y = y;
}

template <typename T>
double Point2D<T>::radius() const {
	return sqrt(getX() * getX()
					   +
				getY() * getY());
}

// търси разстоянието между *this и p
template <typename T>
double Point2D<T>::distance(Point2D p) const {
	/*
	 *
	 return sqrt(pow(p.getX() - getX(), 2) +
			    pow(p.getY() - getY(), 2));
			    */
	p.reflectOrigin();
	p.translate(*this);
	return p.radius();
}

template <typename T>
void Point2D<T>::translate(Point2D const& v) {
	translateX(v.getX());
	translateY(v.getY());
}

template <typename T>
void Point2D<T>::translateX(T const& dx) {
	x += dx;
}

template <typename T>
void Point2D<T>::translateY(T const& dy) {
	y += dy;
}

template <typename T>
void Point2D<T>::reflectOrigin() {
	setX(-getX());
	setY(-getY());
}

template <typename T>
void Point2D<T>::print() const {
	std::cout << '(' << getX() << ','
			         << getY() << ')';
}

// във формат (x,y)
// считаме, че входът е коректен
template <typename T>
void Point2D<T>::read() {
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

#endif
