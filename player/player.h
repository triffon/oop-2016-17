/*
 * player.h
 *
 *  Created on: 23.03.2017 г.
 *      Author: trifon
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

class Player {
protected:

	char* name;		// Име на играча
	int score;		// Резултат в точки

public:

	// Конструктор по подразбиране / с параметри
	Player(char const* n = "Анонимен", int s = 0);

	// Конструктор за копиране
	Player(Player const&);

	// Операция за присвояване
	Player& operator=(Player const& p);

	// Деструктор
	~Player();

	/* Селектори */
	char const* getName() const { return name; }
	int getScore() const { return score; }

	// Извеждане
	void print(std::ostream& os = std::cout) const;

	/* Мутатори */
	void setName(char const* n);
	void setScore(int s) { score = s; }

};

std::istream& operator>>(std::istream& i, Player& r);
std::ostream& operator<<(std::ostream& o, Player const& r);



#endif /* PLAYER_H_ */
