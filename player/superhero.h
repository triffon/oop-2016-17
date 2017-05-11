/*
 * superhero.h
 *
 *  Created on: 11.05.2017 г.
 *      Author: trifon
 */

#ifndef SUPERHERO_H_
#define SUPERHERO_H_

#include "hero.h"

const int SUPER_LEVEL = 5;

class SuperHero : public Hero {
private:

	char* power;
	bool super;

	void setPower(char const*);

public:

	// конструктор
	SuperHero(char const* n = "Анонимен", int s = 0,
				int _l = 1, char const* _p= "неизвестна");

	// Конструктор копиране
	SuperHero(SuperHero const&);

	// Операция за присвояване
	SuperHero& operator=(SuperHero const&);

	// Деструктор
	~SuperHero();

	// селектори
	char const* getPower() const { return power; }
	bool isSuper() const { return super; }

	int getLevel() const;

	// Мутатори
	void becomeSuperHero() { super = true; }
	void stopBeingSuperHero() { super = false; }


	void print(std::ostream& os = std::cout) const;
};



#endif /* SUPERHERO_H_ */
