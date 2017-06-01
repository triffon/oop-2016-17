/*
 * repeat_task.cpp
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#include "repeat_task.h"

RepeatTask::RepeatTask(char const* _name,
					   Task* _baseTask,
					   unsigned _repetitions) :
					   Task(_name),
					   baseTask(_baseTask),
					   repetitions(_repetitions),
					   repeatProgress(0) {}

unsigned RepeatTask::getSize() const {
	return baseTask->getSize() * getRepetitions();
}

unsigned RepeatTask::getProgress() const {
	return getRepeatProgress() * baseTask->getSize() +
			baseTask->getProgress();
}

unsigned RepeatTask::work(unsigned effort) {
	return effort;
}

void RepeatTask::print(std::ostream& os) const {
	os << "повтаряща се ";
	Task::print(os);
	os << ", за която вече са изпълнени " << getRepeatProgress();
	os << " повторения от общо " << getRepetitions();
	os << " на задачата [ ";
	baseTask->print(os);
	os << " ]";
}
