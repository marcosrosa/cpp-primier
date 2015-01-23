//============================================================================
// Name        : inicio.cpp
// Author      : Marcos
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <cctype>
using std::ispunct;

#include <vector>
using std::vector;

#include <stdexcept>
using std::exception;
using std::runtime_error;

//#include "chapter6.h"
#include "SalesData.h"
#include "trem.h"

void sayHello(const string &s1) {
	cout <<"end s1" <<  &s1 << endl;
	cout << "em sayHello -> " << s1 << endl;
}

int calcQuadrado(const int &rVal) {
	return rVal * rVal;
}
void exerciciosParametros(void) {
	cout << "!!!Testes de Passagem por valor Copia"
			" e referencia e ponteiros!!!" << endl;
	string nova("Justiça Federal @ Espirito Santo ~");

	cout << "String -> " << nova << endl;
	cout << "tamanho -> " << nova.size() << endl;
	sayHello(nova);
	cout << "String original -> " << nova << endl;

	// laço for passando argumentos por referência
	for (int x=0; x < 11; x++) {
		cout << "Quadrado de [ " << x << " ] = " << calcQuadrado(x) << endl;
	}

	decltype(nova.size()) qtd_pontuacao = 0;

	for (auto &c : nova) {
		if (ispunct(c))
			qtd_pontuacao++;

	}

	cout << "Pontuacoes em nova: " << qtd_pontuacao << endl;
	cout << nova << endl;

}

void exercVetores(void) {
	cout << "<<exercicios com vetores>>" << endl;
	cout << "Forneça as palavras para incluir no vetor:" << endl;

	string palavra;
	vector<string> plvs;

	while (cin >> palavra) {
		if (!palavra.empty())
			plvs.push_back(palavra);
	}

	cout << "lista de palavras inseridas:" << endl;
	int j = 0;
	// exibe a lista - quatro itens por linha
	for (auto pv : plvs) {
		for (auto &c : pv) {
			c = toupper(c);
		}
		cout << pv << "\t";
		if ( (++j % 4)==0 )
			cout << endl;
	}
	cout << "\nFim da \"lista\" " << endl;
}

int dividirVal(int x, int y) {
	cout << "dividendo: " << x << endl;
	cout << "divisor  : " << y << endl;
	if (y == 0)
		throw runtime_error("Nao Possivel dividir por ZERO!!");
	return x / y;
}

void exercVetores2(void) {
	cout << "<<vetores: 3.23>>" << endl;
	// vi vetor inteiros
	vector<int> vi{3,5,6,7,8,9,4,62,23,10};
	//copia vi -> vo (vetor original)
	const vector<int> vo(vi);

	//modificar os itens de um Vector via ITERATOR
	for (auto it = vi.begin(); it != vi.end(); ++it)
		(*it)*=4;

	// modifica os itens via uma referencia para cada elemento.(+facil)
/*	for(auto &numI : vi) {
		numI *= 2;
	}
*/
	// exibe os numeros originais - (range for)
	for(const auto &numOr : vo) {
		cout << numOr << "\t";
	}
	cout << "\n\t\t\t\t Tudo (x4)" << endl;
	// exibe os numeros modificados
	cout << endl;
	for(auto numIt = vi.begin(); numIt != vi.end(); ++numIt) {
		cout << *numIt << "\t";
	}
	cout << endl;
}

void exercExcecoes(void) {
	cout << "\ndividir por zero:"<< endl;

	try {
		// para teste dvs -> 0
		int dvd = 3453, dvs=0;
		cout << dividirVal(dvd,dvs) << endl;
		cout << "fim try " << dvs << endl;
	}
	catch (std::runtime_error &e) {
		cout << "runtime" << endl;
		cout << e.what() << endl;
	}
	catch (std::exception &ex) {
		cout << "chuchu" << endl;
		cout << ex.what() << endl;
	}

}


int main() {
	//exerciciosParametros();
	//exercVetores2();
	//exercVetores();
	//exercExcecoes();

	SalesData trans("7654321", 7, 75.25);
	SalesData outro("7654321", 3, 80.25);
	SalesData outra("7654322", 4, 84.25);

	vector<SalesData> lstSales;
	cout << "capacidade do vetor: " << lstSales.capacity() << endl;
	lstSales.push_back(trans);
	cout << "capacidade do vetor: " << lstSales.capacity() << endl;
	lstSales.push_back(outro);
	cout << "capacidade do vetor: " << lstSales.capacity() << endl;
	lstSales.push_back(outra);
	cout << "capacidade do vetor: "<< lstSales.capacity() << endl;
	cout << "---------------" << endl;

	for (const auto &sale : lstSales) {
		// print SalesData.h friend
		print(cout, sale);
		cout << "\n---------------" << endl;
	}

	cout << "isbnNo: \t" << trans.getBookNo() << endl;
	cout << "Units : \t" << trans.getUnitsSold() << endl;
	cout << "Lucro : \t" << trans.getRevenue() << endl;

	trans.combine(outro);

	cout << "isbnNo: \t" << trans.getBookNo() << endl;
	cout << "Units : \t" << trans.getUnitsSold() << endl;
	cout << "Lucro : \t" << trans.getRevenue() << endl;

	//SalesData novoItem(cin);

	trem doido;

	doido.doTheTest();


	return 0;
}

