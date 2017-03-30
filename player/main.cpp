/*
 * main.cpp
 *
 *  Created on: 23.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include <cstring>
#include "player.h"

void anonymousPrint(Player p) {
	std::cout << p;
	p.setName("Анонимен");
	std::cout << p;
}

void testPlayer() {
	Player p1("Гандалф Сивия", 45);
	p1.print();
	Player p2 = p1;
	p2.print();
	p2.setName("Гандалф Белия");
	p1.print();
	p2.print();
	anonymousPrint(p2);
	p1.print();
	p2.print();
	// !!! strcpy(p1.getName(), "PWNED!!11!");
	// !!! p1.print();
	Player p3 = "Кетнис Евърдийн";
	// Player p3("Кетнис Евърдийн");
	p3.print();
	// !!! Player p4 = 5;
	anonymousPrint("Фродо");

	std::cin >> p1;
	std::cout << p1;
}

void testDestructor() {
	for(int i = 0; i < 1E8; i++) {
		Player p("Гандалф Сивия", 45);
		p.setScore(50);
		// !!! delete p.getName();
	}

	for(int i = 0; i < 1E8; i++) {
		Player* p = new Player[10];
		delete[] p;
	}

	Player* pa[10];
	for(int i = 0; i < 10; i++) {
		pa[i] = new Player("Орк");
		pa[i]->print();
	}

	delete pa[2];
	delete pa[8];

	for(int i = 0; i < 10; i++)
		if (i != 2 && i != 8)
			delete pa[i];
}

int main() {
	testPlayer();
	// testDestructor();
	return 0;
}



