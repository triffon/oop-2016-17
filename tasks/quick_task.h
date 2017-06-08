/*
 * quick_task.h
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#ifndef QUICK_TASK_H_
#define QUICK_TASK_H_

#include "task.h"

const char KEY_FINISHED[] = "finished";

class QuickTask : public Task {
private:
	bool finished;

	void serializeFinished(std::ostream&) const;
public:

	QuickTask(char const* _name = "<бърза задача>");

	virtual unsigned getSize() const { return 1; }

	virtual unsigned getProgress() const { return finished; }

	virtual unsigned work(unsigned effort = 1);

	virtual void print(std::ostream& os = std::cout) const;

	virtual bool serialize(std::ostream&) const;

	virtual Task* clone() const {
		return new QuickTask(*this);
	}
};



#endif /* QUICK_TASK_H_ */
