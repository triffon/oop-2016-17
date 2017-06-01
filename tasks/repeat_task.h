/*
 * repeat_task.h
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#ifndef REPEAT_TASK_H_
#define REPEAT_TASK_H_

#include "task.h"

class RepeatTask : public Task {
private:
	Task* baseTask;
	unsigned repetitions;
	unsigned repeatProgress;

public:
	RepeatTask(char const* _name, Task* _baseTask,
				unsigned _repetitions);

	unsigned getRepetitions() const {
		return repetitions;
	}

	unsigned getRepeatProgress() const {
		return repeatProgress;
	}

	virtual unsigned getSize() const;

	virtual unsigned getProgress() const;

	virtual unsigned work(unsigned effort = 1);

	virtual void print(std::ostream& os = std::cout) const;
};



#endif /* REPEAT_TASK_H_ */
