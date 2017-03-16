/*
 * lstack.h
 *
 *  Created on: 16.03.2017 г.
 *      Author: trifon
 */

#ifndef LSTACK_H_
#define LSTACK_H_

struct StackElement {
	int data;
	StackElement* next;
};

class LinkedStack {
private:
	StackElement* top;

public:

	// създаване на празен стек
	LinkedStack();

	// проверка дали стек е празен
	bool empty() const;

	// включване на елемент
	void push(int x);

	// изключване на елемент
	int pop();

	// поглеждане на елемента на върха на стека
	int peek() const;
};


#endif /* LSTACK_H_ */
