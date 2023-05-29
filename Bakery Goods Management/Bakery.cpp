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

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <sstream>
#include "Bakery.h"

using namespace std;
namespace sdds
{
	Bakery::Bakery() : goods () {};

	std::ostream& operator << (std::ostream& out, const BakedGood& b) {
		out.unsetf(ios::right);
		//---type
		out << "* ";
		out.width(10);
		out.setf(ios::left);
		out << (b.m_type == BakedType::BREAD? "Bread" : "Pastry");
		
		//---description
		out << " * ";
		out.width(20);
		out << b.m_desc;

		//---Shelf life
		out << " * ";
		out.width(5); 
		out << b.m_day;

		//---Stock
		out << " * ";
		out.width(5);
		out << b.m_quantity;
		out.unsetf(ios::left);

		//---Price
		out.setf(ios::right);
		out << " * ";
		out.width(8);
		out << std::fixed;
		out << std::setprecision(2);
		out << b.m_price;
		out << " * ";
		return out;
	};


	Bakery::Bakery(const std::string& filename) {
		std::ifstream file(filename);
		if (!file.is_open())
			throw invalid_argument ("File can't be opened!");
		else {

			while (!file.eof()) {			
				std::string line{};
				std::string temp{};
				BakedGood good;
				int idx = 0;
				getline (file, line, '\n');
				if (!line.empty()) {

					//---m_type
					temp = line.substr(idx, 8);
					idx += 8;
					size_t pos = temp.find_last_not_of(' ');
					temp.erase(pos + 1);
					good.m_type = (temp == "Bread") ? BakedType::BREAD : BakedType::PASTERY;

					//---m_desc
					temp = "";
					temp = line.substr(idx, 20);
					idx += 20;
					pos = temp.find_last_not_of(' ');
					temp.erase(pos + 1);
					good.m_desc = temp;

					//---shelf life
					temp = "";
					temp = line.substr(idx, 14);
					idx += 14;
					pos = temp.find_last_not_of(' ');
					temp.erase(pos + 1);
					good.m_day = stoi(temp);

					//---stock
					temp = "";
					temp = line.substr(idx, 8);
					idx += 8;
					pos = temp.find_last_not_of(' ');
					temp.erase(pos + 1);
					good.m_quantity = stoi(temp);

					//---price
					temp = "";
					temp = line.substr(idx, 6);
					pos = temp.find_last_not_of(' ');
					temp.erase(pos + 1);
					good.m_price = stod(temp);

					goods.push_back(good);
				}				
			}
		}
	};

	void Bakery::showGoods(std::ostream& os) const {
	
		int total_stock = std::accumulate(goods.begin(), goods.end(), 0, [](int sum, const BakedGood& good) {
				return sum += good.m_quantity;
				});

		double total_price = std::accumulate(goods.begin(), goods.end(), 0.0, [](double sum, const BakedGood& good) {
				return sum += good.m_price;
				});

		std::for_each(goods.begin(), goods.end(), [&](const BakedGood& good) {
				os << good << std::endl;
				});

		os << "Total Stock: " << total_stock << std::endl;
		os << "Total Price: " << total_price << std::endl;
	};

	void Bakery::sortBakery(const std::string field) {
		sort(goods.begin(), goods.end(), [&](BakedGood g1, BakedGood g2) {
			if (field == "Description") return g1.m_desc < g2.m_desc;
			if (field == "Shelf") return g1.m_day < g2.m_day;
			if (field == "Stock") return g1.m_quantity < g2.m_quantity;
			if (field == "Price") return g1.m_price < g2.m_price;
			return false;
			});
	}

	std::vector<BakedGood> Bakery::combine(Bakery& B) {
		this->sortBakery("Price");
		B.sortBakery("Price");
		std::vector<BakedGood> res(this->goods.size() + B.goods.size());
		std::merge(this->goods.begin(), this->goods.end(), B.goods.begin(), B.goods.end(), res.begin(),
			[](const BakedGood& a, const BakedGood& b) {
				return a.m_price < b.m_price;
			});
		return res;
	};

	bool Bakery::inStock(const std::string desc, BakedType type) const {
		auto it = std::find_if(goods.begin(), goods.end(), [=](BakedGood good) {
			return (good.m_type == type) && (good.m_desc.find(desc) != std::string::npos);
			});
		return (it != goods.end());
	};

	std::list<BakedGood> Bakery::outOfStock(BakedType type) const {
		list<BakedGood> res;
		std::copy_if(goods.begin(), goods.end(), std::back_inserter(res), [=](BakedGood good) {
			return good.m_type == type && good.m_quantity == 0;
			});

		res.sort([&](BakedGood g1, BakedGood g2) {
			return g1.m_price < g2.m_price;			
			});
		return res;	
	};
}
 