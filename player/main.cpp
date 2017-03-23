/*
 * main.cpp
 *
 *  Created on: 23.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include "player.h"

void anonymousPrint(Player p) {
	p.setName("Анонимен");
	p.print();
}

void testPlayer() {
	Player p1("Гандалф Сивия", 45);
	p1.print();
	Player p2 = p1;
	p2.print();
	p2.setName("Гандалф Белия");
	p2.print();
	anonymousPrint(p2);
}

int main() {
	testPlayer();
	return 0;
}



