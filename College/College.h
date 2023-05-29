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
#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Person.h"


using namespace std;
namespace sdds
{
	
	class College
	{
		std::vector<Person*> m_persons{};
	public:
		College() {};
		College(const College& C) = delete;
		College& operator = (const College& C) = delete;
		~College();
		College& operator +=(Person* thePerson);

		void display(std::ostream& out) const;
		template <typename T>
		void select(const T& test, std::list<const Person*>& persons) {
			for (auto it = m_persons.begin(); it != m_persons.end(); it++) {
				if (test(*it) == true) {
					persons.push_back(*it);
				}
			}
			
		};
	};
};





#endif