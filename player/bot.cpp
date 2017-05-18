/*
 * bot.cpp
 *
 *  Created on: 18.05.2017 г.
 *      Author: trifon
 */

#include "bot.h"

Bot::Bot(char const* _name,
		int _score,
		char const* _algo,
		double _threshold,
		int _difficulty) :
		Player(_name, _score), AI(_algo, _threshold),
		difficulty(_difficulty)
		{}


void Bot::print(std::ostream& os) const {
	Player::print();
	os << ", който е ";
	AI::print();
	os << " и е бот с трудност " << getDifficulty();
}

