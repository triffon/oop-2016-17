/*
 * main.cpp
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include "quick_task.h"
#include "simple_task.h"
#include "repeat_task.h"

void nl() {
	std::cout << std::endl;
}

void printWork(Task& t, int e = 1) {
	t.print();nl();
	std::cout << "Работим " << e << " единици\n";
	std::cout << "Останаха ни " << t.work(e) << " единици\n";
	t.print();nl();
}

void testWork(Task& t) {
	unsigned e = 0;
	do {
		t.print();nl();
		std::cout << "Колко работа? ";
		std::cin >> e;
		std::cout << "Работим " << e << " единици\n";
		std::cout << "Останаха ни " << t.work(e) << " единици\n";
	} while (!t.isFinished());
	t.print();nl();
}

void testTasks() {
	QuickTask qt("малко контролно");
	printWork(qt, 5);

	SimpleTask st("лекция по ООП", 3);
	printWork(st, 2);
	printWork(st, 2);

	RepeatTask rt("курс ООП",
				  SimpleTask("лекция по ООП", 3),
				  15);
	testWork(rt);

	RepeatTask fmi("бакалавър",
			RepeatTask("семестър",
					RepeatTask("курс",
							SimpleTask("лекция", 3),
							15),
					4),
			8);
	testWork(fmi);
}

int main() {
	testTasks();
	return 0;
}

