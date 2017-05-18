/*
 * superhero.cpp
 *
 *  Created on: 11.05.2017 г.
 *      Author: trifon
 */

#include <cstring>
#include "superhero.h"

SuperHero::SuperHero(char const* _name, int _score,
				int _level, char const* _power) :
	Player(_name, _score),
	Hero("", 0, _level), super(false) {
	setPower(_power);
}

void SuperHero::setPower(char const* _power) {
	power = new char[strlen(_power) + 1];
	strcpy(power, _power);
}

void SuperHero::print(std::ostream& os) const {
	Player::print(os);
	os << " и е супергерой на ниво " << getLevel();
	os << " и притежава суперсила '" << getPower() << "'";
	if (isSuper())
		os << ", която използва в момента";
}

int SuperHero::getLevel() const {
	if (isSuper()) {
		return Hero::getLevel() + SUPER_LEVEL;
	}
	return Hero::getLevel();
}

SuperHero::~SuperHero() {
	std::cerr << "Изтриваме " << power << " " << (void*)power << std::endl;
	delete[] power;
}

SuperHero::SuperHero(SuperHero const& sh) :
		Hero(sh),
		super(sh.super) {
	setPower(sh.power);
}

SuperHero& SuperHero::operator=(SuperHero const& sh) {
	if (this != &sh) {
		// !!! *this = sh;
		//*this = (Hero const&)sh;
		//(Hero&)*this = sh;
		Hero::operator=(sh);
		delete[] power;
		setPower(sh.power);
		super = sh.super;
	}
	return *this;
}
