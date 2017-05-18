/*
 * hero.h
 *
 *  Created on: 11.05.2017 г.
 *      Author: trifon
 */

#ifndef HERO_H_
#define HERO_H_

#include "player.h"

class Hero : virtual public Player {

private:
	int level;

public:

	// Конструктор с параметри и по подразбиране
	Hero(char const* n = "Анонимен", int s = 0,
		int _l = 1);

	// Селектор
	int getLevel() const { return level; }

	// Мутатор
	void setLevel(int _level) { level = _level; }

	// Извеждане
	void printDirect(std::ostream& os = std::cout) const;
	void print(std::ostream& os = std::cout) const;

};



#endif /* HERO_H_ */
