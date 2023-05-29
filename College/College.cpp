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
#include "College.h"

using namespace std;
namespace sdds
{
	College::~College() {
		for (size_t i = 0; i < m_persons.size(); i++) {
			delete m_persons[i];
			m_persons[i] = nullptr;
		}
	};
	College& College::operator +=(Person* thePerson) {
		bool found = false;
		for (size_t i = 0; i < m_persons.size(); i++) {
			if (m_persons[i] == thePerson) {
				found = true;
				break;
			}
		}
		if (!found) {
			m_persons.push_back(thePerson);
		}
		return *this;
	};

	void College::display(std::ostream& out) const {
		out << "------------------------------------------------------------------------------------------------------------------------\n";
		out << "|                                        Test #1 Persons in the college!                                               |\n";
		out << "------------------------------------------------------------------------------------------------------------------------\n";
		for (size_t i = 0; i < m_persons.size(); i++) {
			m_persons[i]->display(out);
			out << endl;
		}

		out << "------------------------------------------------------------------------------------------------------------------------\n";
		out << "|                                        Test #2 Persons in the college!                                               |\n";
		out << "------------------------------------------------------------------------------------------------------------------------\n";
		for (vector<Person*>::const_iterator it = m_persons.begin(); it != m_persons.end(); it++) {
			out.setf(ios::left);
			out << "| ";

			//---status---
			out.width(10);
			out.fill(' ');
			out << (*it)->status();

			//---id---
			out << "| ";
			out.width(10);
			out.fill(' ');
			out << (*it)->id();

			//---name---
			out << "| ";
			out.width(20);
			out.fill(' ');
			out << (*it)->name();

			//---age---
			out << " | ";
			out.width(3);
			out.fill(' ');
			out << (*it)->age() << " |" << endl;
		}
		out << "------------------------------------------------------------------------------------------------------------------------\n";
	};
	
}