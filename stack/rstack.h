/*
 * rstack.h
 *
 *  Created on: 16.03.2017 г.
 *      Author: trifon
 */

#ifndef RSTACK_H_
#define RSTACK_H_

#include "abstract_stack.h"

const int INITIAL = 10;

class ResizingStack : public AbstractStack<int> {
private:
	int* a;
	int top;	  // Индекс на последния елемент в стека
	int capacity; // Капацитет на стека

	// Проверка дали стекът е пълен
	bool full() const;

	// Разширяване на стека
	void resize();

	// Копиране на паметта на стека от друго място
	void copy(int const*);

	// Изтриване на паметта
	void eraseStack();

	// Копиране на стека
	void copyStack(ResizingStack const&);

public:

	// създаване на празен стек
	ResizingStack();

	// Конструктор за копиране
	ResizingStack(ResizingStack const&);

	// Операция за присвояване
	ResizingStack& operator=(ResizingStack const&);

	// унищожаване на стека
	~ResizingStack();

	// проверка дали стек е празен
	bool empty() const;

	// включване на елемент
	void push(int const& x);

	// изключване на елемент
	int pop();

	// поглеждане на елемента на върха на стека
	int peek() const;
};



#endif /* RSTACK_H_ */
