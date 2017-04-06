/*
 * streams.cpp
 *
 *  Created on: 6.04.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include <sstream>

int main() {
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


