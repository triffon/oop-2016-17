/*
 * stack.cpp
 *
 *  Created on: 9.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include "stack.h"

Stack::Stack() : top(-1) {}

bool Stack::empty() const {
	return top == -1;
}

bool Stack::full() const {
	return top == MAX - 1;
}

void Stack::push(int x) {
	if (full()) {
		std::cerr << "Опит за включване в пълен стек!\n";
	} else
		a[++top] = x;
}

int Stack::pop() {
	if (empty()) {
		// Стекът е празен
		std::cerr << "Опит за изключване на елемент от празен стек!\n";
		return 0;
	}
	return a[top--];
}

int Stack::peek() const {
	if (empty()) {
		// Стекът е празен
		std::cerr << "Опит за достъп до върха на празен стек!\n";
		return 0;
	}
	return a[top];
}
