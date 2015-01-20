/*
 * fact.cpp
 *
 *  Created on: 15/01/2015
 *      Author: jesmrfd
 */

#include "chapter6.h"

int exercFact(int val) {
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}


void exercSwap(int &pa, int &pb) {
    int temp= pa;
	pa = pb;
	pb = temp;
}

