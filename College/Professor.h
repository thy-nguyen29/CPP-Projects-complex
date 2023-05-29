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
#ifndef SDDS_PROFESSOR_H
#define SDDS_PROFESSOR_H
#include <iostream>
#include <string>
#include "Employee.h"


namespace sdds
{
	class Professor : public Employee
	{
		std::string m_department{};
	public:
		Professor();
		Professor(std::istream& in);
		void display(std::ostream& out) const;
		std::string status() const;
		std::string department() const;

	};

}


#endif

