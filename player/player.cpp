/*
 * player.cpp
 *
 *  Created on: 23.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include <cstring>
#include "player.h"

Player::Player(char const* n, int s) : score(s) {
	setName(n);
}

void Player::setName(char const* n) {
	strncpy(name, n, MAX);
	name[MAX - 1] = '\0';
}

void Player::print() const {
	std::cout << "Име: "      << getName()  << std::endl
			  << "Резултат: " << getScore() << std::endl;
}
