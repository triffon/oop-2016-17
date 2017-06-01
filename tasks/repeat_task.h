/*
 * repeat_task.h
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#ifndef REPEAT_TASK_H_
#define REPEAT_TASK_H_

#include "simple_task.h"

class RepeatTask : public SimpleTask {
private:
	Task* baseTask;

public:
	RepeatTask(char const* _name, Task* _baseTask,
				unsigned _repetitions);

	unsigned getRepetitions() const {
		return SimpleTask::getSize();
	}

	unsigned getRepeatProgress() const {
		return SimpleTask::getProgress();
	}

	virtual unsigned getSize() const;

	virtual unsigned getProgress() const;

	virtual unsigned work(unsigned effort = 1);

	virtual void print(std::ostream& os = std::cout) const;
};



#endif /* REPEAT_TASK_H_ */
