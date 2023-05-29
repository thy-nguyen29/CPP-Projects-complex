/*
*****************************************************************************
						  Workshop - #2 - Part2
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NDD
Completed date: Jan 26, 2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_PROTEINDATABASE_H
#define	SDDS_PROTEINDATABASE_H
#include <iostream>
#include <string>
#include <iomanip>
#include <cstddef>


namespace sdds
{
	class ProteinDatabase
	{
		std::string* m_string; //array of strings
		int stringCt; //number of strings in array
	public:
		ProteinDatabase();
		ProteinDatabase(const char* filename);
		ProteinDatabase(const ProteinDatabase& P);
		ProteinDatabase(ProteinDatabase&& P)noexcept;
		ProteinDatabase& operator = (const ProteinDatabase& P);
		ProteinDatabase& operator = (ProteinDatabase&& P)noexcept;
		~ProteinDatabase();

		size_t size();
		std::string operator[](size_t i);

	};


}

#endif