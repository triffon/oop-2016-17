/*
 * task.h
 *
 *  Created on: 25.05.2017 г.
 *      Author: trifon
 */

#ifndef TASK_H_
#define TASK_H_

class Task : public Printable {
private:
	char* name;

public:
	Task(char const* _name);

	// голяма четворка

	virtual int getTime() const = 0;

	virtual int getProgress() const = 0;

	double getPercentage() const {
		return (double)getProgress() / getTime();
	}

	virtual void work(int time = 1) = 0;

	char const* getName() const { return name; }
};


#endif /* TASK_H_ */
