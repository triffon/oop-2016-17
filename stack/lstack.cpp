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

void LinkedStack::eraseStack() {
	// !!! delete top;
	// !!! delete[] top;
	while (!empty())
		pop();
}

LinkedStack::~LinkedStack() {
	eraseStack();
}

/*
LinkedStack::LinkedStack(LinkedStack const& ls) :
	top(nullptr) {

	// ако ls е празен, няма какво да правим повече
	if (ls.empty())
		return;

	// сигурни сме, че в ls има поне един елемент

	// копираме първия елемент
	StackElement* lastCopied = new StackElement;
	lastCopied->data = ls.top->data;

	// първият копиран елемент е върхът на стека
	top = lastCopied;

	// копираме останалите от втория елемент нататък
	for(StackElement* toCopy = ls.top->next;
			toCopy != nullptr;
			toCopy = toCopy -> next) {
		// правим копие на клетката, която сочи toCopy
		StackElement* copied = new StackElement;
		copied->data = toCopy->data;
		lastCopied->next = copied;
		lastCopied = copied;
	}

	// Последният елемент няма следващ
	lastCopied->next = nullptr;
}

*/

void LinkedStack::copy(StackElement* toCopy) {
	if (toCopy == nullptr)
		return;
	// сигурен съм, че има поне един елемент
	// Копирам стека от втория елемент нататък
	copy(toCopy->next);
	// добавям и първия елемент отгоре
	push(toCopy->data);
}

void LinkedStack::copyStack(LinkedStack const& ls) {
	top = nullptr;
	copy(ls.top);
}

LinkedStack::LinkedStack(LinkedStack const& ls) {
	copyStack(ls);
}

/*
LinkedStack::LinkedStack(LinkedStack const& ls) :
		top(nullptr) {
	for(StackElement* toCopy = ls.top;
			toCopy != nullptr;
			toCopy = toCopy -> next) {
		push(toCopy->data);
	}
}
*/

LinkedStack& LinkedStack::operator=(LinkedStack const& ls) {
	if (this != &ls) {
		eraseStack();
		copyStack(ls);
	}
	return *this;
}
