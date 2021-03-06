/*
 * main.cpp
 *
 *  Created on: 23.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include <cstring>
#include "player.h"
#include "hero.h"
#include "superhero.h"
#include "ai.h"
#include "bot.h"
#include "boss.h"

void anonymousPrint(Player p) {
	std::cout << p;
	p.setName("Анонимен");
	std::cout << p;
}

void testPlayer() {
	Player p1("Гандалф Сивия", 45);
	p1.print();
	Player p2;
	p2 = p1;
	// !!! p2 = p2;
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

void testInheritance() {
	Player p("Гандалф Сивия", 45);
	Hero h("Кетнис Евърдийн", 50, 3);
	p.print();std::cout << std::endl;
	h.print();std::cout << std::endl;
	std::cout << p;
	std::cout << h;
	Player* p2 = &h;
	p2->print();std::cout << std::endl;
	h.setScore(55);
	p2->print();std::cout << std::endl;
	// !!!
	// !!! Hero* h2 = (Hero*)&p;
	//h2->print();std::cout << std::endl;
	// !!! Hero& h3 = (Hero&)*p2;
	// Hero& h3 = *(Hero*)p2;
	//h3.print();std::cout << std::endl;
}

void nl() {
	std::cout << std::endl;
}

Hero* battle(Hero& h1, Hero& h2) {
	if (h1.getLevel() > h2.getLevel())
		return &h1;
	if (h1.getLevel() < h2.getLevel())
		return &h2;
	return nullptr;
}

void fight(Hero& h1, Hero& h2, int prize) {
	std::cout << "Битка между:\n";
	h1.print();nl();
	std::cout << "И\n";
	h2.print();nl();
	Hero* winner = battle(h1, h2);
	if (winner != NULL) {
		winner->setScore(winner->getScore() + prize);
		std::cout << "Победител е:\n";
		winner->print();
	} else
		std::cout << "Няма победител!\n";
}

void testBattle() {
	Player catniss("Кетнис Евърдийн", 50);
	Hero gandalf("Гандалф Сивия", 45, 3);
	SuperHero superman("Супермен", 10, 2, "летене");
	catniss.print();nl();
	gandalf.print();nl();
	superman.print();nl();
	superman.becomeSuperHero();
	superman.print();nl();

	Hero gandalfw; //= gandalf;
	gandalfw = gandalf;
	gandalfw.setName("Гандалф Белия");
	gandalf.print();nl();
	gandalfw.print();nl();

	SuperHero superwoman;// = superman;
	superwoman = superman;
	superwoman.setName("Супержена");
	superwoman.print();nl();
	superman.print();nl();

	superman.stopBeingSuperHero();
	fight(gandalf, superman, 10);
	superman.becomeSuperHero();
	fight(gandalf, superman, 20);
}

/*
class ChessPlayer : public Player {
private:
	int elo;
};
*/

void testMultipleInheritance() {
	AI ai("минимакс", 5.3);
	ai.print();nl();

	Bot bot("Deep Thought", 10, "минимакс", 5.3, 20);
	bot.print();nl();
	// ((Player const&)bot).print();
	// bot.Player::print();

	Player& p = bot;
	p.print();nl();

	AI* pai = &bot;
	pai->print();nl();

	Boss boss("Саурон", 50, 20, "Тъмни сили", 2.8,
			  100, 1000);
	boss.print();nl();
	// !!!! boss.setName("Sauron");
	// !!!! boss.Player::setName("Sauron");
	boss.Bot::setName("Sauron");
	// !!! (Player&)boss.setName("Sauron");
	((Player&)(Bot&)boss).setName("Sauron");
	boss.print();nl();
	boss.prettyPrint();

	Bot* b = &boss;
	b->print();nl();

	Hero gandalf("Гандалф Сивия", 45, 3);
	// !!! gandalf.print();
	Player* g = &gandalf;
	g->print();
	Hero* h = &gandalf;
	// !!! h->print();
}

void testDestructors() {
	while (true) {
		AI* p = new Boss;
		delete p;
	}
}

void testPrintable() {
	Printable* p = new Boss("Саурон", 50, 20, "Тъмни сили", 2.8,
			  100, 1000);
	p->print();nl();
	p = new AI("минимакс", 5.3);
	p->print();nl();

	Printable* printables[] = {
			new Boss("Саурон", 50, 20, "Тъмни сили", 2.8,
						  100, 1000),
			new AI("минимакс", 5.3),
			new Hero("Гандалф Сивия", 45, 3),
			new SuperHero("Супермен", 10, 2, "летене"),
			new Bot("Deep Thought", 10, "минимакс", 5.3, 20)
	};

	/*
	Printable& printables[] = {
			Boss(...),
			AI(...),
			Hero(...),
			....
	};
	*/
	for(int i = 0; i < 5; i++) {
		printables[i]->print();nl();
	}
	for(int i = 0; i < 5; i++)
		delete printables[i];
}

int main() {
	// testPlayer();
	// testDestructor();
	// testInheritance();
	// testBattle();

	// ChessPlayer cp;
	// testMultipleInheritance();
	// testDestructors();
	testPrintable();
	return 0;
}



