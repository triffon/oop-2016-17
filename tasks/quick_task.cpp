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

void QuickTask::serializeFinished(std::ostream& os) const {
	serializeKeyIntValue(os, KEY_FINISHED, finished);
}

bool QuickTask::serialize(std::ostream& os) const {
	startSerialize(os);
	serializeName(os);
	serializeFinished(os);
	finishSerialize(os);
	return os.good();
}

