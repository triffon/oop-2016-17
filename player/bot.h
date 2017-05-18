/*
 * bot.h
 *
 *  Created on: 18.05.2017 г.
 *      Author: trifon
 */

#ifndef BOT_H_
#define BOT_H_

#include <iostream>

#include "player.h"
#include "ai.h"

class Bot : virtual public Player, public AI {
private:
	int difficulty;

public:

	Bot(char const* _name = "<бот>",
		int _score = 0,
		char const* _algo = "<случайност>",
		double _threshold = 0,
		int _difficulty = 1);

	int getDifficulty() const { return difficulty; }

	void print(std::ostream& = std::cout) const;
};



#endif /* BOT_H_ */
