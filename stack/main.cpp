/*
 * main.cpp
 *
 *  Created on: 9.03.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include "stack.h"
#include "rstack.h"
#include "lstack.cpp"

// typedef Stack MyStack;
// typedef ResizingStack MyStack;
typedef LinkedStack<int> MyStack;

// s += x
/*
void operator+=(MyStack& s, int x) {
	s.push(x);
}
*/

// s + x
MyStack operator+(MyStack const& s, int x) {
	MyStack s2 = s;
	s2.push(x);
	return s2;
}

// x + s
MyStack operator+(int x, MyStack s) {
	return s + x;
}

void testStack() {
	MyStack s;
	for(int i = 1; i <= 10; i++)
		s += i;
		// s.operator+=(i);
		// operator+=(s, i);

	//MyStack s2 = s + 200;
	MyStack s2 = 200 + s;
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
	LinkedStack<char> opStack;
	LinkedStack<int>  dataStack;
	while (*s) {
		if (*s == '('); // Пропускаме

		if (*s >= '0' && *s <= '9')
			dataStack.push(*s - '0');
		if (*s == '+' || *s == '-' || *s == '*' || *s == '/')
			opStack.push(*s);

		if (*s == ')') {
			// Трябва да сметнем!
			int b = dataStack.pop();
			char op = opStack.pop();
			int a = dataStack.pop();
			int r = 0;

			switch (op) {
				case '+' : r = a + b;break;
				case '-' : r = a - b;break;
				case '*' : r = a * b;break;
				case '/' : if (b != 0) r = a / b;
			}
			dataStack.push(r);
		}
		s++;
	}
	return dataStack.pop();
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
	LinkedStack<char> stack;
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
	testBaseConvert();
	testCalculateExpr();
	testCheckParentheses();
	return 0;
}
