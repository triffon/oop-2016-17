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
		 Hero(_name, _score, _level),
		 Bot(_name, _score, _algo, _threshold, _difficulty),
		 damage(_damage) {}

void Boss::print(std::ostream& os) const {
	Hero::print();
	os << ", който е ";
	Bot::print();
	os << " и нанася поражения " << getDamage()
		<< " точки";
}


