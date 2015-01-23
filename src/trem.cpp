/*
 * trem.cpp
 *
 *  Created on: 20/01/2015
 *      Author: jesmrfd
 */

#include <iostream>
#include <assert.h>

#include "trem.h"

//const int trem::cnt1 = 20;
int trem::cnt2 = 30;
constexpr int trem::sequencia[];

int trem::arrayTest() {
	std::cout << "class-> trem.cpp method -> arrayTest()" << std::endl;
	int ia[] = {8,7,6};
	for (int x = 0; x < 3; ++x) {
		std::cout << "then num:"<< ia[x] << std::endl;
	}

	std::cout << "o array static " << cnt1 << std::endl;

	for (int k = 0; k < 5; ++k)
		std::cout << "item array: " << sequencia[k] << std::endl;

	std::cout << "fim - arrayTest()" << std::endl;

	return 0;
}

void trem::doTheTest() {
	assert(std::cout << "class-> trem.cpp method -> doTheTest()" << std::endl);
	arrayTest();
	assert(std::cout << "fim -> trem.cpp method -> doTheTest()" << std::endl);
}
