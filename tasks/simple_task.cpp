/*
 * simple_task.cpp
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#include <cmath>
#include "simple_task.h"

SimpleTask::SimpleTask(char const* _name,
					   unsigned _size) :
	Task(_name), size(_size), progress(0) {}

unsigned SimpleTask::work(unsigned effort) {
	unsigned spent = std::min(effort, size - progress);
	effort -= spent;
	progress += spent;
	return effort;
}

void SimpleTask::print(std::ostream& os) const {
	os << "проста ";
	Task::print();
	os << " с големина " << getSize();
	os << " и напредък " << getProgress();
}


