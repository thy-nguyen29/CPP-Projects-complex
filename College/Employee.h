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
#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
#include <iostream>
#include <string>
#include "Person.h"


namespace sdds
{
	class Employee : public Person
	{
		std::string m_name;
		std::string m_id;
		size_t m_age = 0;
	public:
		Employee();
		Employee(std::istream& is);
		std::string status() const;
		std::string name() const;
		std::string id() const;
		std::string age() const;
		void display(std::ostream& out) const;
		

	};


}





#endif 
