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
#include "Professor.h"
#include "Utilities.h"




using namespace std;
namespace sdds
{
	Professor::Professor() {};
	Professor::Professor(std::istream& in) : Employee(in) {
		std::string department;
		getline(in, department, '\n');
		in.peek();
		removeSpace(department);
		this->m_department = department;
	};

	void Professor::display(std::ostream& out) const {
		Employee::display(out);
		out << m_department << "| " << status();
	};

	std::string Professor::status() const {
		return "Professor";
	};

	std::string Professor::department() const {
		return m_department;
	};



}