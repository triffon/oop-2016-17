/*
 * ai.cpp
 *
 *  Created on: 18.05.2017 г.
 *      Author: trifon
 */

#include <cstring>
#include "ai.h"

void AI::setAlgorithm(const char* _algo) {
	algorithm = new char[strlen(_algo) + 1];
	strcpy(algorithm, _algo);
}


AI::AI(const char* _algo, double _threshold) :
	threshold(_threshold){
	setAlgorithm(_algo);
}


AI::AI(const AI& ai) {
	threshold = ai.threshold;
	setAlgorithm(ai.algorithm);
}


AI& AI::operator=(const AI& ai) {
	if (this != &ai) {
		delete[] algorithm;
		setAlgorithm(ai.algorithm);
		threshold = ai.threshold;
	}
	return *this;
}


AI::~AI() {
	delete[] algorithm;
}


void AI::print(std::ostream& os) const {
	std::cout << "Изкуствен интелект с алгоритъм '"
			<< getAlgorithm() << "' и праг "
			<< getThreshold();
}




