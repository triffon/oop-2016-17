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
	p.print();
	p.setName("Анонимен");
	p.print();
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
}

void testDestructor() {
	for(int i = 0; i < 1E8; i++) {
		Player p("Гандалф Сивия", 45);
		p.setScore(50);
	}

}

int main() {
	// testPlayer();
	testDestructor();
	return 0;
}



