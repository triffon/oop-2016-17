#include "hero.h"

Hero::Hero(char const* _name, int _score, int _level) :
//	!!! name(_name), score(_score), level(_level) {}
	Player(_name, _score), level(_level) {}

void Hero::print(std::ostream& os) const {
	Player::print(os);
	printDirect(os);
}

void Hero::printDirect(std::ostream& os) const {
	os << " и е герой на ниво " << getLevel();
}
