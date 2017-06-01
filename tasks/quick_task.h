/*
 * quick_task.h
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#ifndef QUICK_TASK_H_
#define QUICK_TASK_H_

#include "task.h"

class QuickTask : public Task {
private:
	bool finished;

public:

	QuickTask(char const* _name);

	virtual unsigned getSize() const { return 1; }

	virtual unsigned getProgress() const { return finished; }

	virtual unsigned work(unsigned effort = 1);

	virtual void print(std::ostream& os = std::cout) const;

	virtual Task* clone() const {
		return new QuickTask(*this);
	}
};



#endif /* QUICK_TASK_H_ */
