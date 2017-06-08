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

char const KEY_SUBTASKS[] = "subtasks";

class ComplexTask : public SimpleTask,
					private LinkedStack<Task*> {
private:
	void copy(ComplexTask const&);
	void clean();

	void serializeSubTasks(std::ostream& os) const;

public:
	ComplexTask(char const* _name = "<сложна задача>");

	ComplexTask(ComplexTask const&);

	ComplexTask& operator=(ComplexTask const&);

	virtual ~ComplexTask();

	virtual unsigned work(unsigned effort = 1);

	virtual void print(std::ostream& os = std::cout) const;

	virtual bool serialize(std::ostream&) const;

	virtual char const* getType() const {
		return "ComplexTask";
	}

	virtual Task* clone() const {
		return new ComplexTask(*this);
	}

	void addTask(Task const&);
};



#endif /* COMPLEX_TASK_H_ */
