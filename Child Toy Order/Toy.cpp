/*
*****************************************************************************
						  Workshop - #4 - Part2
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NDD
Completed date: Feb 10, 2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <iomanip>
#include "Toy.h"

using namespace std;
namespace sdds
{
	Toy::Toy() {};
	Toy::~Toy() {};

	Toy::Toy(const std::string& toy) {
		string id, num, price, name;
		handle(toy, id, name, num, price);
		m_id = stoi(id);
		m_numItem = stoi(num);
		m_price = stod(price);
		m_toyName = name;
	};
	
	void Toy::update(int numItems) {
		m_numItem = numItems;
	};

	Toy::Toy(const Toy& T) {
		this->m_id = T.m_id;
		this->m_toyName = T.m_toyName;
		this->m_numItem = T.m_numItem;
		this->m_price = T.m_price;
	}

	Toy::Toy(Toy&& T) noexcept {
		this->m_id = T.m_id;
		this->m_toyName = T.m_toyName;
		this->m_numItem = T.m_numItem;
		this->m_price = T.m_price;
	}

	Toy& Toy::operator = (const Toy& T) {
		if (this != &T) {
			this->m_id = T.m_id;
			this->m_toyName = T.m_toyName;
			this->m_numItem = T.m_numItem;
			this->m_price = T.m_price;
		}
		return *this;
	};

	Toy& Toy::operator = (Toy&& T) noexcept {
		if (this != &T) {
			this->m_id = T.m_id;
			this->m_toyName = T.m_toyName;
			this->m_numItem = T.m_numItem;
			this->m_price = T.m_price;
		}
		return *this;
	}
	std::ostream& operator << (std::ostream& os, const Toy& T) {
		double subTotal = T.m_numItem * T.m_price;
		double tax = subTotal * T.hst;
		double total = subTotal + tax;
		os << "Toy";
		os.width(8);
		os.fill(' ');
		os << T.m_id << ":";

		os.width(18);
		os.fill(' ');
		os.setf(ios::right);
		os << T.m_toyName;
		os.unsetf(ios::right);

		os.width(3);
		os.fill(' ');
		os << T.m_numItem << " items";

		os.width(8);
		os.fill(' ');
		os << T.m_price << "/item  subtotal:";
		os.unsetf(ios::right);

		os.width(7);
		os.fill(' ');
		os.setf(ios::right);
		os << subTotal << " tax:";

		os.width(6);
		os.fill(' ');
		os << fixed << setprecision(2) << tax;
		os << " total:";

		os.width(7);
		os.fill(' ');
		os << fixed << setprecision(2) << total;
		os.unsetf(ios::right);
		os << endl;
		return os;
	};

	void trim(string& str) {
		size_t n = str.size();
		size_t i = 0;
		size_t countSpace = 0;
		while (i < n && str[i] == ' ') {
			i++;
			countSpace++;
		}

		if (countSpace > 0) {
			str.erase(0, countSpace);
		}
		//---------------------------------------------------
		i = str.size() - 1;
		countSpace = 0;
		while (i >= 0 && str[i] == ' ') {
			i--;
			countSpace++;
		}

		if (countSpace > 0) {
			str.erase(i + 1, countSpace);
		}
	}

	void handle(const string& inputString, string& id, string& name, string& num, string& price) {
		//ID:NAME:NUM:PRICE
		string delim = ":";
		size_t start = 0;
		size_t end = inputString.find(delim, 0);

		id = inputString.substr(start, end);

		start = end + 1;
		end = inputString.find(delim, start);
		name = inputString.substr(start, end - start);
		start = end + 1;
		end = inputString.find(delim, start);
		num = inputString.substr(start, end - start);

		start = end + 1;
		end = inputString.find(delim, start);
		price = inputString.substr(start);

		trim(id);
		trim(name);
		trim(num);
		trim(price);
	}
}