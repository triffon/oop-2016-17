/*
 * lstack.cpp
 *
 *  Created on: 16.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include "lstack.h"

LinkedStack::LinkedStack() : top(nullptr) {}

bool LinkedStack::empty() const {
	return top == nullptr;
}

void LinkedStack::push(int x) {
	StackElement* p = new StackElement;
	p->data = x;
	p->next = top;
	top = p;
}

int LinkedStack::pop() {
	if (empty()) {
		// Стекът е празен
		std::cerr << "Опит за изключване на елемент от празен стек!\n";
		return 0;
	}
	StackElement* p = top;
	top = top->next;
	int x = p->data;
	delete p;
	return x;
}

int LinkedStack::peek() const {
	if (empty()) {
		// Стекът е празен
		std::cerr << "Опит за достъп до върха на празен стек!\n";
		return 0;
	}
	return top->data;
}

LinkedStack::~LinkedStack() {
	// !!! delete top;
	// !!! delete[] top;
	while (!empty())
		pop();
}

LinkedStack::LinkedStack(LinkedStack const& ls) :
	top(nullptr) {
	// !!! Безкрайна рекурсия!
	LinkedStack lscopy = ls;
	while (!lscopy.empty()) {
		push(lscopy.pop());
	}
}
