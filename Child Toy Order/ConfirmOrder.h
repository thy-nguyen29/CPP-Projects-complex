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
#ifndef SDDS_CONFIRMORDER_H
#define SDDS_CONFIRMORDER_H
#include <iostream>
#include <string>
#include "Toy.h"


namespace sdds
{
	class ConfirmOrder
	{
		const sdds::Toy** toy{};
		size_t m_size{};
	public:
		ConfirmOrder();
		ConfirmOrder(const ConfirmOrder& C);
		ConfirmOrder(ConfirmOrder&& C) noexcept;
		~ConfirmOrder();
		ConfirmOrder& operator = (const ConfirmOrder& C);
		ConfirmOrder& operator = (ConfirmOrder&& C) noexcept;
		ConfirmOrder& operator+=(const sdds::Toy& toy);
		ConfirmOrder& operator-=(const sdds::Toy& toy);
		std::ostream& display(std::ostream& os) const;
		friend std::ostream& operator << (std::ostream& os, const ConfirmOrder& C);
	};




}



#endif