/*
 * streams.cpp
 *
 *  Created on: 6.04.2017 г.
 *      Author: trifon
 */

#include <iomanip>
#include <iostream>
#include <sstream>

void logState(std::istream& is) {
	std::clog << "Състояние на потока: " << is.rdstate() << std::endl;
}

int safeReadInt(std::istream& is = std::cin) {
	int n;
	logState(is);
	is >> n;
	logState(is);
	while (!is) {
		if (is.eof()) {
			std::cerr << "Край на потока!" << std::endl;
			return 0;
		}
		is.clear();
		logState(is);
		// Изчистване на лошия символ
		is.get();
		// пробваме да четем отново
		is >> n;
		logState(is);
	}
	return n;
}

void testSafeRead() {
	std::cout << "Прочетено: " << safeReadInt() << std::endl;
}

void testInOut() {
	char data[] = { 65, 66, 67, 68 };
	unsigned int x = 68;
	x <<= 8;
	x += 67;
	x <<= 8;
	x += 66;
	x <<= 8;
	x += 65;
	std::cout.write(data, 4);
	std::cout << std::endl;
	std::cout << x << std::endl;
	std::cout.write((const char*)&x, sizeof(int)) << std::endl;

	//std::istringstream iss("AB\nA\nB");
	std::istream& iss = std::cin;

	iss.getline(data, 4);
	std::cout << iss.gcount() << std::endl;

	iss.read(data, 3);
	std::cout << (int)data[0] << ' ' <<
		   	(int)data[1] << ' ' <<
			(int)data[2] << ' ' << std::endl;
}

void testManipulator() {
	std::cout << 42 << std::endl;
	std::cout << std::showbase << std::hex << std::setw(10) << 42 << std::endl;
}

int main() {
	// testInOut();
	// testSafeRead();
	testManipulator();
}
