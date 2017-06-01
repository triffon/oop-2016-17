/*
 * task.h
 *
 *  Created on: 25.05.2017 г.
 *      Author: trifon
 */

#ifndef TASK_H_
#define TASK_H_

#include "printable.h"
#include "cloneable.h"

class Task : public Printable, public Cloneable<Task> {
private:
	char* name;

	void setName(char const* _name);

public:
	Task(char const* _name = "<задача>");

	// голяма четворка
	Task(Task const&);

	Task& operator=(Task const&);

	virtual ~Task();

	double getPercentage() const {
		return (double)getProgress() / getSize();
	}

	bool isFinished() const {
		return getProgress() == getSize();
	}

	char const* getName() const { return name; }

	virtual unsigned getSize() const = 0;

	virtual unsigned getProgress() const = 0;

	// Инварианта: work връща число >= 0
	// Инварианта: work използва максимално количество усилие
	virtual unsigned work(unsigned effort = 1) = 0;

	virtual void print(std::ostream& os = std::cout) const;
};


#endif /* TASK_H_ */
