/*
 * complex_task.h
 *
 *  Created on: 8.06.2017 г.
 *      Author: trifon
 */

#ifndef COMPLEX_TASK_H_
#define COMPLEX_TASK_H_

#include "simple_task.h"
#include "../stack/lstack.cpp"

class ComplexTask : public SimpleTask,
					private LinkedStack<Task*> {
public:
	ComplexTask(char const* _name = "<сложна задача>");

	virtual unsigned work(unsigned effort = 1);

	virtual void print(std::ostream& os = std::cout) const;

	virtual Task* clone() const {
		return new ComplexTask(*this);
	}

	void addTask(Task const&);
};



#endif /* COMPLEX_TASK_H_ */
