/*
 * point2d.h
 *
 *  Created on: 2.03.2017 г.
 *      Author: trifon
 */

#ifndef POINT2D_H_
#define POINT2D_H_

// Точка в равнината
class Point2D {
private:
	double x, y; // координатите на точката

public:

	/** Конструктори **/

	// конструктор по подразбиране
	Point2D();

	// конструктор с параметри
	Point2D(double x, double y);

	/** Селектори **/

	// Селектори за координати
	double getX() const { return x; }
	double getY() const { return y; }

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
	void translateX(double dx);
	void translateY(double dy);
	void translate(Point2D const& v);

	// Въвеждане
	void read();

	// симетрия относно x == y
	// за домашно
	void reflect();

	// симетрия относно началото на координатната система
	void reflectOrigin();

	// установяване на координати
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }

	// ротация относно origin с ъгъл angle
	// за домашно
	void rotate(Point2D const& origin, double angle);
};



#endif /* POINT2D_H_ */
