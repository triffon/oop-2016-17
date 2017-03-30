/*
 * main.cpp
 *
 *  Created on: 9.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include "stack.h"
#include "rstack.h"
#include "lstack.h"

// typedef Stack MyStack;
// typedef ResizingStack MyStack;
typedef LinkedStack MyStack;

void testStack() {
	MyStack s;
	for(int i = 1; i <= 10; i++)
		s.push(i);

	MyStack s2 = s;
	s2.pop();
	int* p = new int;
	s2.push(100);
	std::cout << s2.peek() << std::endl;

	while (!s.empty())
		std::cout << s.pop() << ' ';

	while (!s2.empty())
		std::cout << s2.pop() << ' ';

	return;

	// тестване за Memory leak
	for(int i = 0; i < 1E8; i++) {
		MyStack* s = new MyStack;
		s->push(1);
		// s.pop();
		delete s;
	}


}

char digitToChar(int d) {
	if (d < 10)
		return '0' + d;
	return 'A' + (d - 10);
}

void baseConvert(int n, int k) {
	MyStack s;
	if (n == 0)
		s.push(0);

	while (n > 0) {
		s.push(n % k);
		n /= k;
	}

	while (!s.empty())
		std::cout << digitToChar(s.pop());
	std::cout << std::endl;
}

void testBaseConvert() {
	baseConvert(20, 2);
	baseConvert(04712, 8);
	baseConvert(124124, 10);
	baseConvert(0x5A8B0, 16);
}

/*
 * <израз> ::= <цифра> | (<израз><операция><израз>)
 * <израз>
 */

int calculateExpr(char const* s) {
	MyStack stack;
	while (*s) {
		if (*s == '('); // Пропускаме

		if (*s >= '0' && *s <= '9')
			stack.push(*s - '0');
		if (*s == '+' || *s == '-' || *s == '*' || *s == '/')
			stack.push(*s);

		if (*s == ')') {
			// Трябва да сметнем!
			int b = stack.pop();
			char op = stack.pop();
			int a = stack.pop();
			int r = 0;

			switch (op) {
				case '+' : r = a + b;break;
				case '-' : r = a - b;break;
				case '*' : r = a * b;break;
				case '/' : if (b != 0) r = a / b;
			}
			stack.push(r);
		}
		s++;
	}
	return stack.pop();
}

void testCalculateExpr() {
	std::cout << calculateExpr("((2+(4*5))-3)") << std::endl;
	std::cout << calculateExpr("1") << std::endl;
	std::cout << calculateExpr("((2*(1+3))-7)") << std::endl;
	std::cout << calculateExpr("(1+2)") << std::endl;
}

bool match(char open, char close) {
	return open == '(' && close == ')' ||
	       open == '[' && close == ']' ||
		   open == '{' && close == '}';
}

bool checkParentheses(char const* s) {
	MyStack stack;
	while (*s) {

		if (*s == '(' || *s == '[' || *s == '{')
			stack.push(*s);

		if (*s == ')' || *s == ']' || *s == '}')
			if (stack.empty() // Значи имаме повече затварящи от отварящи!
					||
				!match(stack.pop(), *s)) // Значи скобите не съвпадат по тип!
				return false;

		s++;
	}
	return stack.empty(); // ако стекът не е празен, значи имаме повече отварящи от затварящи скоби!
}

void printTest(char const *s) {
	std::cout << s << " -> " << checkParentheses(s) << std::endl;
}

void testCheckParentheses() {
	printTest("()");
	printTest("(]");
	printTest("nothing");
	printTest("(([{[{}]}([])]))");
	printTest("(([{[{}]}[])]))");
	printTest("(([{[{}]}([])))");
	printTest("(");
	printTest("]");
	printTest("((((((((((())))))))))");
	printTest("((((((((((())))))))))))");
	printTest(")(");
	printTest("(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((())))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))");
}

int main() {
	testStack();
	// testBaseConvert();
	// testCalculateExpr();
	// testCheckParentheses();
	return 0;
}
