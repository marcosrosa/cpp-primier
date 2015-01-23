/*
 * SalesData.h
 *
 *  Created on: 16/01/2015
 *      Author: jesmrfd
 */

#ifndef SALESDATA_H_
#define SALESDATA_H_

#include <string>
#include <iostream>


class SalesData {
	// nao usuaria funcoes friends
	friend SalesData      add(const SalesData &, const SalesData &);
	friend std::istream & read(std::istream &, SalesData &);
	friend std::ostream & print(std::ostream &, const SalesData &);
	public:
		// construtores
		SalesData() = default;
		SalesData(const std::string &s, unsigned n, double p) :
			bookNo(s), unitsSold(n), revenue(p*n) {}
		SalesData(const std::string &s) : bookNo(s) {}
		SalesData(std::istream &);

		//friend std::istream& read(&std::istream, SalesData &item);

		// metodos publicos
		std::string getBookNo()    const { return bookNo; }

		unsigned    getUnitsSold() const { return unitsSold; }
		void        setUnitsSold(unsigned x) { x > 0 ? unitsSold = x : unitsSold=1; }

		double      getRevenue()   const { return revenue; }
		void        setRevenue(double rv) { revenue = rv; }

		SalesData & combine(const SalesData &);
		double      getAvgPrice()  const { return avgPrice(); }
	private:
		// dados da classe
		std::string bookNo;
		unsigned unitsSold = 1;
		double revenue = 0.0;

		// funcao privada
		double avgPrice() const { return unitsSold ? revenue/unitsSold : 0; }
};

/* declarations of friends function for others to user */
SalesData      add(const SalesData &, const SalesData &);
std::istream & read(std::istream &, SalesData &);
std::ostream & print(std::ostream &, const SalesData &);

#endif /* SALESDATA_H_ */
