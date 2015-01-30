/*
 * StrBlob.cpp
 *
 *  Created on: 30/01/2015
 *      Author: jesmrfd
 */



#include "StrBlob.h"
#include <string>
using std::string;

#include<stdexcept>

StrBlob::StrBlob() : data ( std::make_shared<std::vector<string>>()) { }

StrBlob::StrBlob(std::initializer_list<string> il) : data
		( std::make_shared<std::vector<string>>(il)) { }

void StrBlob::check(size_type i, const string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}
