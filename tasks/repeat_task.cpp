/*
 * repeat_task.cpp
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#include "repeat_task.h"

RepeatTask::RepeatTask(char const* _name,
					   Task const* _baseTask,
					   unsigned _repetitions) :
					   SimpleTask(_name, _repetitions),
					   baseTask(_baseTask),
					   currentTask(nullptr) {
	reset();
}

unsigned RepeatTask::getSize() const {
	return baseTask->getSize() * getRepetitions();
}

unsigned RepeatTask::getProgress() const {
	return getRepeatProgress() * baseTask->getSize() +
			currentTask->getProgress();
}

unsigned RepeatTask::work(unsigned effort) {
	// фаза 1: завършване на текущото повторение
	effort = currentTask->work(effort);
	if (currentTask->isFinished()) {
		// фаза 2: изпълняване на някакъв брой повторения
		reset();
		unsigned repeatEffort = effort / baseTask->getSize();
		unsigned leftRepeatEffort = SimpleTask::work(repeatEffort + 1);
		unsigned spentRepeatEffort = repeatEffort - leftRepeatEffort;
		effort -= spentRepeatEffort * baseTask->getSize();
		if (!SimpleTask::isFinished()) {
			// Фаза 3: започване на нова задача
			effort = currentTask->work(effort);
		}
	}
	return effort;
}

void RepeatTask::print(std::ostream& os) const {
	os << "повтаряща се ";
	Task::print(os);
	os << ", за която вече са изпълнени " << getRepeatProgress();
	os << " повторения от общо " << getRepetitions();
	os << " на задачата [ ";
	currentTask->print(os);
	os << " ]";
}

void RepeatTask::reset() {
	delete currentTask;
	currentTask = baseTask->clone();
}
