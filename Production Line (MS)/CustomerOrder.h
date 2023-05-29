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

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <iostream>
#include <string>
#include "Station.h"

namespace sdds
{

	
	class CustomerOrder
	{		
		struct Item
		{
			std::string m_itemName{};
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};

		std::string m_name;	
		std::string m_product;
		size_t m_cntItem{0};
		Item** m_lstItem = nullptr;
	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);
		CustomerOrder (const CustomerOrder& C);
		CustomerOrder (CustomerOrder&& C) noexcept;
		CustomerOrder& operator = (const CustomerOrder& C) = delete;
		CustomerOrder& operator = (CustomerOrder&& C) noexcept;
		~CustomerOrder();

		bool isOrderFilled() const;;

		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};


}

#endif