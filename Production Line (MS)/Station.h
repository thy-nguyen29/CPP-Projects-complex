/*
*****************************************************************************
						  Milestone - #3
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NDD
Completed date: Apr 06, 2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>
#include <string>


namespace sdds
{
	

	class Station
	{
		size_t m_id;
		std::string m_name;
		std::string m_desc;
		size_t m_serialNumber;
		size_t m_quantity;
		
	public:
		Station();
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;


	};


}



#endif