/*
 * trem.cpp
 *
 *  Created on: 20/01/2015
 *      Author: jesmrfd
 */

#include <ctime>
#include <cwchar>
#include <locale>
#include <iostream>
#include <assert.h>

#include <string>
using std::string;

#include <map>
using std::map;

#include <utility>
using std::pair;

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

void trem::apresData() {

	std::wcout << "User-preferred Alô locale setting is " << std::locale("").name().c_str() << '\n';
	// on startup, the global locale is the "C" locale
	//std::locale localid = getloc();
    std::time_t t = std::time(NULL);
    wchar_t wstr[100];
    if(std::wcsftime(wstr, 100, L"%d/%m/%Y", std::localtime(&t))) {
        std::wcout << wstr << '\n';
    }
}

void trem::exercMaps() {
	map<string, size_t> word_count;
	string word;
	std::cout << "Escreva uma Frase:" << std::endl;
	//while(std::cin >> word)
	//	++word_count[word];

	// o retorno de inseert para map
	// pair<map<string, size_t>::iterator, boll>
	while(std::cin >> word)
		++word_count.insert(make_pair(word,0)).first->second;


	//auto novo = word_count.find("chuchu");
	// auto aponta para este tipo abaixo.
	map<string,size_t>::iterator novo = word_count.find("tomate");
	if (novo != word_count.end())
		std::cout << "localizado :" << novo->second << std::endl;

	for (const auto &w : word_count) {
		std::cout << w.first << " ocorre " << w.second <<
				(( w.second>1) ? "vezes" : "vez") << std::endl;
	}


}
