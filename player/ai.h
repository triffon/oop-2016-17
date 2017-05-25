/*
 * ai.h
 *
 *  Created on: 18.05.2017 г.
 *      Author: trifon
 */

#ifndef AI_H_
#define AI_H_

#include <iostream>

class AI {
private:

	char* algorithm;
	double threshold;

	// мутатор
	void setAlgorithm(char const*);

public:

	// Голяма четворка
	AI(const char* = "<случайност>", double = 0);

	AI(AI const&);

	AI& operator=(AI const&);

	virtual ~AI();

	// Селектори
	char const* getAlgorithm() const { return algorithm; }
	double getThreshold() const { return threshold; }

	// Извеждане
	virtual void print(std::ostream& = std::cout) const;
};



#endif /* AI_H_ */
