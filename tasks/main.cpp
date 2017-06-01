/*
 * main.cpp
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include "quick_task.h"

void nl() {
	std::cout << std::endl;
}

void printWork(Task& t, int e = 1) {
	t.print();nl();
	std::cout << "Работим " << e << " единици\n";
	std::cout << "Останаха ни " << t.work(e) << " единици\n";
	t.print();nl();
}

void testTasks() {
	QuickTask qt("малко контролно");
	printWork(qt, 5);
}

int main() {
	testTasks();
	return 0;
}

