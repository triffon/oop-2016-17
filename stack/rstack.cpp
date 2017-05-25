/*
 * rResizingStack.cpp
 *
 *  Created on: 16.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include "rstack.h"

ResizingStack::ResizingStack() : top(-1), capacity(INITIAL) {
	a = new int[capacity];
}

bool ResizingStack::empty() const {
	return top == -1;
}

bool ResizingStack::full() const {
	return top == capacity - 1;
}

void ResizingStack::push(int const& x) {
	if (full()) {
		resize();
	}
	a[++top] = x;
}

int ResizingStack::pop() {
	if (empty()) {
		// Стекът е празен
		std::cerr << "Опит за изключване на елемент от празен стек!\n";
		return 0;
	}
	return a[top--];
}

int ResizingStack::peek() const {
	if (empty()) {
		// Стекът е празен
		std::cerr << "Опит за достъп до върха на празен стек!\n";
		return 0;
	}
	return a[top];
}

void ResizingStack::resize() {
	int* olda = a;
	a = new int[2 * capacity];
	copy(olda);
	// легализираме удвояването на капацитета
	capacity *= 2;
	// Изтриваме старата памет
	delete[] olda;
	std::cerr << "Стекът е разширен до " << capacity << " елемента.\n";
}

void ResizingStack::copy(int const* other) {
	// Прехвърляме данните
	for(int i = 0; i < capacity; i++)
		a[i] = other[i];
}

void ResizingStack::eraseStack() {
	delete[] a;
}

ResizingStack::~ResizingStack() {
	eraseStack();
}

void ResizingStack::copyStack(ResizingStack const& rs) {
	top = rs.top;
	capacity = rs.capacity;
	a = new int[capacity];
	copy(rs.a);

}

ResizingStack::ResizingStack(ResizingStack const& rs) {
	copyStack(rs);
}

ResizingStack& ResizingStack::operator=(ResizingStack const& rs) {
	if (this != &rs) {
		/** !!!
		 * !!!!
		~ResizingStack();
		ResizingStack(rs);
		*/
		eraseStack();
		copyStack(rs);
	}
	return *this;
}


