/*
*****************************************************************************
						  Workshop - #7 - part2
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NDD
Completed date: Mar 15, 2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H
#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace sdds
{
	enum class BakedType
	{
		BREAD, PASTERY
	};

	typedef struct
	{
		BakedType m_type;
		int m_day;
		int m_quantity;
		double m_price;
		std::string m_desc;
		
	}BakedGood;

	std::ostream& operator<<(std::ostream& out, const BakedGood& b);

	class Bakery
	{
		std::vector<BakedGood> goods;
	public:
		Bakery();
		Bakery(const std::string& filename);
		void showGoods(std::ostream& os) const;
		void sortBakery(const std::string field);
		std::vector<BakedGood> combine(Bakery& B);
		bool inStock(const std::string desc, BakedType type) const;
		std::list<BakedGood> outOfStock(BakedType type) const;

	};
	





}








#endif