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
#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H
#include <iostream>
#include <string>
#include "Toy.h"

namespace sdds
{
	class Child
	{
		std::string m_name;
		int m_age = 0;
		const sdds::Toy** toy{};
		size_t m_count{};

	public:
		Child();
		~Child();
		Child(std::string name, int age, const Toy* toys[], size_t count);
		Child(const Child& C);
		Child( Child&& C) noexcept;
		Child& operator = (const Child& C);
		Child& operator = (Child&& C) noexcept;
		size_t size() const;
		friend std::ostream& operator << (std::ostream& os, const Child& C);
	};

}

#endif

