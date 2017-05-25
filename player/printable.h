/*
 * printable.h
 *
 *  Created on: 25.05.2017 г.
 *      Author: trifon
 */

#ifndef PRINTABLE_H_
#define PRINTABLE_H_

#include <iostream>

class Printable {
public:
	virtual void print(std::ostream& = std::cout) const = 0;

	virtual ~Printable() {}
};

class PrettyPrintable : public Printable {
	void prettyPrint() {
		std::cout << "---\n";
		print();
	}
};
// Остава абстрактен


#endif /* PRINTABLE_H_ */
