/*
*****************************************************************************
						  Workshop - #1 - Part2
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NDD
Completed date: Jan 16, 2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_FOODORDER_H
#define	SDDS_FOODORDER_H
#include <iostream>
#include <cstring>
#include <iomanip>

extern double g_taxrate ;
extern double g_dailydiscount ;

namespace sdds
{
	class FoodOrder
	{
		char m_name[10]{};
		char* m_foodDesc = nullptr;
		double m_price = 0;
		bool m_dailySpecial = false;
	public:
		FoodOrder();
		FoodOrder(const FoodOrder& F);
		FoodOrder& operator =(const FoodOrder& F);
		~FoodOrder();

		std::istream& read (std::istream& is) ;
		void display ();
	};

}

#endif // !SDDS_FOODORDER_H

