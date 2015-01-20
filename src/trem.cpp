/*
 * trem.cpp
 *
 *  Created on: 20/01/2015
 *      Author: jesmrfd
 */

#include <iostream>

#include "trem.h"

//const int trem::cnt1 = 20;
int trem::cnt2 = 30;
constexpr int trem::sequencia[];

int trem::arrayTest() {
	int ia[] = {8,7,6};
	for (int x = 0; x < 3; ++x) {
		std::cout << "then num:"<< ia[x] << std::endl;
	}

	std::cout << "o array static " << cnt1 << std::endl;

	for (int k = 0; k < 5; ++k)
		std::cout << "item array: " << sequencia[k] << std::endl;


	return 0;
}

void trem::doTheTest() {
	arrayTest();
}
