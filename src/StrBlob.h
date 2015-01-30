/*
 * StrBlob.h
 *
 *  Created on: 30/01/2015
 *      Author: jesmrfd
 */

#ifndef STRBLOB_H_
#define STRBLOB_H_

#include <memory>

class StrBlob {
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// add remove elements
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();
	// element acess
	std::string& front();
	std::string& back();
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;

};

#endif /* STRBLOB_H_ */
