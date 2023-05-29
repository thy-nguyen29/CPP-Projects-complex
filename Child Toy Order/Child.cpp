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
#include <iostream>
#include <string>
#include "Child.h"

using namespace std;
namespace sdds
{
	Child::Child() {
		m_name[0] = '\0';
		m_age = 0;
		toy = nullptr;
		m_count = 0;
	};

	Child::~Child() {
		for (size_t i = 0; i < m_count; i++) {
			delete toy[i];
		}
		delete[] toy;
	};

	Child::Child(std::string name, int age, const Toy* toys[], size_t count) {
		m_name = name;
		m_age = age;
		m_count = count;
		toy = new const Toy* [count];
		for (size_t i = 0; i < count; i++) {
			toy[i] = new const Toy (*toys[i]);
		}
	};

	Child::Child(const Child& C) {		
			this->m_name = C.m_name;
			this->m_age = C.m_age;
			this->m_count = C.m_count;
			this->toy = new const Toy * [m_count];
			for (size_t i = 0; i < m_count; i++) {
				this->toy[i] = new const Toy (*C.toy[i]);
			}
		
	};

	Child::Child(Child&& C) noexcept {
		operator = (move(C));
	};

	Child& Child::operator = (const Child& C) {
		if (this != &C) {
			for (size_t i = 0; i < this->m_count; i++) {
				delete toy[i];
			}
			delete[] toy;

			this->m_name = C.m_name;
			this->m_age = C.m_age;
			this->m_count = C.m_count;
			this->toy = new const Toy * [m_count];
			for (size_t i = 0; i < m_count; i++) {
				this->toy[i] = new const Toy(*C.toy[i]);
			}
		}
		return *this;
	};


	Child& Child::operator = (Child&& C) noexcept {
		if (this != &C) {
			for (size_t i = 0; i < this->m_count; i++) {
				delete toy[i];
			}
			delete[] toy;
			this->m_name = C.m_name;
			this->m_age = C.m_age;
			this->m_count = C.m_count;
			this->toy = C.toy;

			C.toy = nullptr;
			C.m_count = 0;
			C.m_age = 0;
			C.m_name = "";
		}
		return *this;
	};

	size_t Child::size() const {
		return m_count;
	};



	std::ostream& operator << (std::ostream& os, const Child& C) {
		static int CALL_CNT = 1;
		os << "--------------------------" << endl;
		os << "Child " << CALL_CNT << ": "<< C.m_name << " " << C.m_age << " years old:" << endl;
		os << "--------------------------" << endl;
		CALL_CNT++;
		if (C.m_count < 1) {
			os << "This child has no toys!" << endl; 
		}
		else {
			for (size_t i = 0; i < C.m_count; i++) {
				os << *C.toy[i];
			}
		}
		os << "--------------------------" << endl;
		return os;
	};




}