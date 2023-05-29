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
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#include <iostream>
#include <string>
#include "Person.h"

namespace sdds
{
	class Student : public Person
	{
		std::string m_name;	
		std::string m_id;
		std::string* m_courses{};
		size_t m_age;
		size_t m_count;
	public:
		Student();
		Student(std::istream& is);
		~Student();
		std::string status() const;
		std::string name() const;
		std::string age() const;
		std::string id() const;
		void display(std::ostream& out) const;


	};


}



#endif

