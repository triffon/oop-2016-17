/*
 * files.cpp
 *
 *  Created on: 20.04.2017 г.
 *      Author: trifon
 */

#include <iostream>
#include <fstream>

const int MAX = 100;

void testifiles() {
	std::ifstream prog("../streams/streams.cpp");
	char line[MAX];
	for(int i = 0; i < 10; i++) {
		prog.getline(line, MAX);
		std::cout << line << std::endl;
	}

	std::ifstream exe("../streams/Debug/streams",
					 std::ios::in | std::ios::binary);
	char data[MAX];
	exe.read(data, MAX);
	for(int i = 0; i < MAX; i++)
		std::cout << std::hex << (int)data[i] << std::endl;
}

void testofiles() {
	std::ofstream email("email.txt");
	email << "Hi, there!" << std::endl << std::endl;
	email << "Thought you might be interested to know";
	email << " that the first " << MAX << " natural numbers are:" << std::endl;
	for(int i = 0; i < MAX; i++)
		email << i << ' ';
	email << "KTHXBYE!" << std::endl;
	email.close();
	std::clog << "Wrote file email.txt!\n";
	std::cout << "Press enter to continue...";
	std::cin.get();

	std::ofstream data("numbers.dat",
			std::ios::out | std::ios::binary);
	int numbers[MAX];
	for(int i = 0; i < MAX; i++)
		numbers[i] = i * 2;
	data.write((const char*)numbers, MAX * sizeof(int));
	std::clog << "Wrote file numbers.dat\n";
}

void testiofiles() {
	std::fstream data("numbers.dat",
						std::ios::in | std::ios::out |
						std::ios::binary);
	int numbers[MAX];
	for (int i = 0; i < 3; i++) {
		data.read((char*)numbers, 2 * sizeof(int));
		numbers[0] += numbers[1];
		data.write((const char*)numbers, 2 * sizeof(int));
	}
	std::streampos pos = data.tellp();
	data.seekp(-2 * sizeof(int), std::ios::end);
	numbers[0] = 100;
	numbers[1] = 200;
	data.write((char const*)numbers, 2 * sizeof(int));
	data.seekp(pos);
	data.write((char const*)numbers, 2 * sizeof(int));
	std::clog << "Modified file numbers.dat\n";
}

int main() {
	// testifiles();
	// testofiles();
	testiofiles();
	return 0;
}


