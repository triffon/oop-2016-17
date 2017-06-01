/*
 * task.cpp
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#include <cstring>
#include "task.h"

Task::Task(char const* _name) :
	name(nullptr) {
	setName(_name);
}

Task::Task(Task const& task) :
	name(nullptr) {
	setName(task.name);
}

Task& Task::operator=(Task const& task) {
	if (this != &task) {
		setName(task.name);
	}
	return *this;
}

Task::~Task() {
	delete[] name;
}

void Task::setName(char const* _name) {
	delete[] name;
	if (_name != nullptr) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	} else
		name = nullptr;
}

void Task::print(std::ostream& os) const {
	os << "задача '" << getName() << "'";
}





