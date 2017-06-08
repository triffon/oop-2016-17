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
#include "complex_task.h"

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

void testComplexTask() {
	ComplexTask oop("ООП");
	oop.addTask(QuickTask("нанасяне на оценки"));
	oop.addTask(SimpleTask("изпит за ниво 6", 2));
	oop.addTask(SimpleTask("изпит за нива 4 и 5", 3));
	oop.addTask(SimpleTask("изпит за ниво 3", 2));

	ComplexTask oopWeek("седмични занятия");
	oopWeek.addTask(SimpleTask("лекция", 3));
	oopWeek.addTask(SimpleTask("упражнение", 2));

	oop.addTask(RepeatTask("занятия", oopWeek, 15));

	oop.print();

	testWork(oop);
}

void testSerialize() {
	QuickTask qt("нанасяне на оценки");
	qt.serialize(std::cout);

	SimpleTask st("изпит за ниво 6", 2);
	st.serialize(std::cout);
}

int main() {
	// testTasks();
	// testComplexTask();
	testSerialize();
	return 0;
}

