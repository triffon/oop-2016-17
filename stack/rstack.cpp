/*
 * rResizingStack.cpp
 *
 *  Created on: 16.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include "rstack.h"

ResizingStack::ResizingStack() {
	capacity = INITIAL;
	a = new int[capacity];
	top = -1;
}

bool ResizingStack::empty() const {
	return top == -1;
}

bool ResizingStack::full() const {
	return top == capacity - 1;
}

void ResizingStack::push(int x) {
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
	// Прехвърляме данните
	for(int i = 0; i < capacity; i++)
		a[i] = olda[i];
	// легализираме удвояването на капацитета
	capacity *= 2;
	delete[] olda;
	std::cerr << "Стекът е разширен до " << capacity << " елемента.\n";
}

ResizingStack::~ResizingStack() {
	delete[] a;
}
