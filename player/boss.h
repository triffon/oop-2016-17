/*
 * boss.h
 *
 *  Created on: 18.05.2017 г.
 *      Author: trifon
 */

#ifndef BOSS_H_
#define BOSS_H_

#include "hero.h"
#include "bot.h"

class Boss : /* virtual public Player, */ public Hero, public Bot {
private:
	int damage;

public:

	Boss(char const* _name = "<бос>", int _score = 20,
		 int _level = 10,
		 char const* _algo = "<тайна>", double _threshold = 1.3,
		 int _difficulty = 5,
		 int _damage = 8);

	int getDamage() const { return damage; }

	void printDirect(std::ostream& os = std::cout) const;
	void print(std::ostream& os = std::cout) const;

};



#endif /* BOSS_H_ */
