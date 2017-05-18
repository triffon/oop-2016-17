/*
 * boss.cpp
 *
 *  Created on: 18.05.2017 г.
 *      Author: trifon
 */

#include "boss.h"

Boss::Boss(char const* _name, int _score,
		 int _level,
		 char const* _algo, double _threshold,
		 int _difficulty,
		 int _damage) :
		 Hero("", 0, _level),
		 Bot("", 0, _algo, _threshold, _difficulty),
		 Player(_name, _score),
		 damage(_damage) {}

void Boss::print(std::ostream& os) const {
	Player::print(os);
	printDirect(os);
}

void Boss::printDirect(std::ostream& os) const {
	Hero::printDirect(os);
	os << ", който е ";
	Bot::printDirect(os);
	os << " и нанася поражения " << getDamage()
		<< " точки";
}


