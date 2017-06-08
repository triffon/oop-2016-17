/*
 * complex_task.cpp
 *
 *  Created on: 8.06.2017 г.
 *      Author: trifon
 */

#include "complex_task.h"

ComplexTask::ComplexTask(char const* _name) :
	SimpleTask(_name, 0) {}

void ComplexTask::addTask(Task const& t) {
	if (getProgress() == 0) {
		push(t.clone());
		size += t.getSize();
	}
}

void ComplexTask::print(std::ostream& os) const {
	os << "сложна ";
	Task::print(os);
	os << "с големина " << getSize() << " и прогрес " << getProgress();
	os << ", която съдържа следните задачи: {\n";
	LinkedStack<Task*> copy = *this;
	while (!copy.empty()) {
		copy.pop()->print(os);
		os << "\n";
	}
	os << "}\n";
}

unsigned ComplexTask::work(unsigned effort) {
	unsigned originalEffort = effort;
	while (!empty() && effort > 0) {
		Task* currentTask = peek();
		effort = currentTask->work(effort);
		if (currentTask->isFinished())
			delete pop();
	}
	progress += originalEffort - effort;
	return effort;
}
