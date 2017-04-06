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

std::ostream& operator<<(std::ostream& o, Player const& p) {
	return o << "Име: "      << p.getName()  << std::endl
			 << "Резултат: " << p.getScore() << std::endl;
}

std::istream& operator>>(std::istream& i, Player& p) {
	const int MAX = 1000;
	char name[MAX];
	double score;
	i.getline(name, MAX) >> score;
	p.setName(name);
	p.setScore(score);
	return i;
}


Player& Player::operator=(Player const& p) {
	if (this != &p) {
	// !!! if (*this != p) {
		// (*this).operator!=(p);
		setName(p.getName());
		score = p.score;
	}
	return *this;
}
