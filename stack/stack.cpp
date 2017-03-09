/*
 * stack.cpp
 *
 *  Created on: 9.03.2017 г.
 *      Author: trifon
 */

#include "stack.h"

Stack::Stack() {
	top = -1;
}

bool Stack::empty() const {
	return top == -1;
}

void Stack::push(int x) {
	a[++top] = x;
}

int Stack::pop() {
	return a[top--];
}

int Stack::peek() const {
	return a[top];
}
