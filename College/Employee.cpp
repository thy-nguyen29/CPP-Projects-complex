/*
*****************************************************************************
						  Workshop - #6 - part2
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NDD
Completed date: Mar 03, 2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Employee.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
	Employee::Employee() {
		m_name = '\0';
		m_id = '\0';
		m_age = 0;
	
	};
	Employee::Employee(std::istream& is) {
		string name, age, id;
		getline (is, name, ',');
		removeSpace(name);
		this->m_name = name;

		getline (is, age, ',');
		removeSpace(age);
		for (size_t i = 0; i < age.size(); i++) {
			if (!isdigit(age[i])) {
				throw name + "++Invalid record!";
			}
		}
		this->m_age = stoi(age);


		//getline (is, id, '\n');
		is >> id;
		if (id[id.size() - 1] == ',') {
			id.erase(id.size() - 1, 1);
		}
		else {
			is.ignore(1000, '\n');
		}
		removeSpace(id);
		if (id[0] != 'E') {
			throw name + "++Invalid record!";
		}
		this->m_id = id;
	
	};
	std::string Employee::status() const {
		return "Employee";
	};
	std::string Employee::name() const {
		return m_name;
	};
	std::string Employee::id() const {
		return m_id;
	};
	std::string Employee::age() const {
		return to_string(m_age);
	};
	void Employee::display(std::ostream& out) const {
		out.setf(ios::left);
		out << "| ";

		//---status---
		out.width(10);
		out.fill(' ');
		out << Employee::status();

		//---id---
		out << "| ";
		out.width(10);
		out.fill(' ');
		out << this->m_id;

		//---name---
		out << "| ";
		out.width(20);
		out.fill(' ');
		out << this->m_name;

		//---age---
		out << " | ";
		out.width(3);
		out.fill(' ');
		out << this->m_age << " |";
	};
	

}
