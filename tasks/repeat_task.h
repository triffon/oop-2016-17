/*
 * repeat_task.h
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#ifndef REPEAT_TASK_H_
#define REPEAT_TASK_H_

#include "simple_task.h"

const char KEY_REPETITIONS[] = "repetitions";
const char KEY_REPEAT_PROGRESS[] = "repeatProgress";
const char KEY_BASE_TASK[] = "baseTask";
const char KEY_CURRENT_TASK[] = "currentTask";

class RepeatTask : public SimpleTask {
private:
	Task const* baseTask;
	Task* currentTask;

	void reset();

	void copy(RepeatTask const&);
	void clean();

	void serializeRepetitions(std::ostream& os) const;
	void serializeRepeatProgress(std::ostream& os) const;
	void serializeBaseTask(std::ostream& os) const;
	void serializeCurrentTask(std::ostream& os) const;

public:
	RepeatTask(char const* _name = "<повтаряема задача>",
			   Task const& _baseTask = SimpleTask(),
			   unsigned _repetitions = 1);

	RepeatTask(RepeatTask const&);

	RepeatTask& operator=(RepeatTask const&);

	virtual ~RepeatTask();

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

	virtual bool serialize(std::ostream&) const;

	virtual char const* getType() const {
		return "RepeatTask";
	}

	virtual Task* clone() const {
		return new RepeatTask(*this);
	}
};



#endif /* REPEAT_TASK_H_ */
