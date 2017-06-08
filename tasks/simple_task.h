/*
 * simple_task.h
 *
 *  Created on: 1.06.2017 г.
 *      Author: trifon
 */

#ifndef SIMPLE_TASK_H_
#define SIMPLE_TASK_H_

#include "task.h"

class SimpleTask : public Task {
private:
	unsigned size;
	unsigned progress;
	// Инварианта: 0 <= progress <= size

public:
	SimpleTask(char const* _name = "<проста задача>",
			   unsigned _size = 1);

	virtual unsigned getSize() const { return size; }

	virtual unsigned getProgress() const { return progress; }

	virtual unsigned work(unsigned effort = 1);

	virtual void print(std::ostream& os = std::cout) const;

	virtual Task* clone() const {
		return new SimpleTask(*this);
	}
};



#endif /* SIMPLE_TASK_H_ */
