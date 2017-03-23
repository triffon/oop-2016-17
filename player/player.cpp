/*
 * player.cpp
 *
 *  Created on: 23.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include <cstring>
#include "player.h"

Player::Player(char const* n, int s) : name(nullptr), score(s) {
	setName(n);
}

Player::Player(Player const& p) : name(nullptr), score(p.score) {
	setName(p.name);
}

void Player::setName(char const* n) {
	// Може би в name вече има заделена памет?
	// изтриваме старата памет
	delete[] name;
	// Заделяме нова, точно колкото трябва
	name = new char[strlen(n) + 1];
	// копираме името
	strcpy(name, n);
}

void Player::print() const {
	std::cout << "Име: "      << getName()  << std::endl
			  << "Резултат: " << getScore() << std::endl;
}

Player::~Player() {
	delete[] name;
}
