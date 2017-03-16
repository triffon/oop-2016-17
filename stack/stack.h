/*
 * stack.h
 *
 *  Created on: 9.03.2017 г.
 *      Author: trifon
 */

#ifndef STACK_H_
#define STACK_H_

// typedef int Data;

const int MAX = 100;

class Stack {
private:
	int a[MAX];
	int top;	// Индекс на последния елемент в стека

	bool full() const;

public:

	// създаване на празен стек
	Stack();

	// проверка дали стек е празен
	bool empty() const;

	// включване на елемент
	void push(int x);

	// изключване на елемент
	int pop();

	// поглеждане на елемента на върха на стека
	int peek() const;
};



#endif /* STACK_H_ */
