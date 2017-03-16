/*
 * rstack.h
 *
 *  Created on: 16.03.2017 г.
 *      Author: trifon
 */

#ifndef RSTACK_H_
#define RSTACK_H_

const int INITIAL = 10;

class ResizingStack {
private:
	int* a;
	int top;	  // Индекс на последния елемент в стека
	int capacity; // Капацитет на стека

	// Проверка дали стекът е пълен
	bool full() const;

	// Разширяване на стека
	void resize();

public:

	// създаване на празен стек
	ResizingStack();

	// проверка дали стек е празен
	bool empty() const;

	// включване на елемент
	void push(int x);

	// изключване на елемент
	int pop();

	// поглеждане на елемента на върха на стека
	int peek() const;
};



#endif /* RSTACK_H_ */
