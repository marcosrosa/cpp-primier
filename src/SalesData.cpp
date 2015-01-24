/*
 * SalesData.cpp
 *
 *  Created on: 16/01/2015
 *      Author: jesmrfd
 */

#include "SalesData.h"

SalesData::SalesData(std::istream &is) {
	read(is, *this);
}

SalesData& SalesData::combine(const SalesData &rhs) {
	unitsSold += rhs.unitsSold;
	revenue += rhs.revenue;
	return *this;
}

std::istream& read(std::istream &is, SalesData &item) {
	double price = 0;
	is >> item.bookNo  >> item.unitsSold >> price;
	item.revenue = price * item.unitsSold;
	return is;

}

std::ostream& print(std::ostream &os, const SalesData &item) {
	os << item.getBookNo() << "\t\t" << item.getUnitsSold() << "\t"
			<< item.getRevenue() << "\t" << item.avgPrice();
	return os;
}

SalesData add(const SalesData &lhs, const SalesData &rhs) {
	SalesData sum = lhs;
	sum.combine(rhs);
	return sum;
}

