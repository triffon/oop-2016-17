/*
 * abstract_stack.h
 *
 *  Created on: 25.05.2017 г.
 *      Author: trifon
 */

#ifndef ABSTRACT_STACK_H_
#define ABSTRACT_STACK_H_

template <typename T>
class AbstractStack {
public:
	// проверка дали стек е празен
	virtual bool empty() const = 0;

	// включване на елемент
	virtual void push(T const& x) = 0;

	// изключване на елемент
	virtual T pop() = 0;

	// поглеждане на елемента на върха на стека
	virtual T peek() const = 0;

	virtual ~AbstractStack() {}
};



#endif /* ABSTRACT_STACK_H_ */
