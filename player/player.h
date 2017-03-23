/*
 * player.h
 *
 *  Created on: 23.03.2017 г.
 *      Author: trifon
 */

#ifndef PLAYER_H_
#define PLAYER_H_

int const MAX = 100;

class Player {
private:

	char name[MAX];		// Име на играча
	int score;			// Резултат в точки

public:

	// Конструктор по подразбиране / с параметри
	Player(char const* n = "Анонимен", int s = 0);

	/* Селектори */
	char const* getName() const { return name; }
	int getScore() const { return score; }

	// Извеждане
	void print() const;

	/* Мутатори */
	void setName(char const* n);
	void setScore(int s) { score = s; }

};



#endif /* PLAYER_H_ */
