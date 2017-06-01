/*
 * quick_task.cpp
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#include "quick_task.h"

QuickTask::QuickTask(char const* _name) :
	Task(_name), finished(false) {}

unsigned QuickTask::work(unsigned effort) {
	if (effort > 0 && !finished) {
		effort--;
		finished = true;
	}
	return effort;
}

void QuickTask::print(std::ostream& os) const {
	os << "бърза ";
	Task::print(os);
	os << ", която ";
	if (!finished)
		os << "НЕ ";
	os << "е завършена";
}
