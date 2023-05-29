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

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "CustomerOrder.h"
#include "Utilities.h"


using namespace std;
namespace sdds
{
	static size_t m_widthField;

	CustomerOrder::CustomerOrder() {
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;	
	};

	CustomerOrder::CustomerOrder(const std::string& str) {
		Utilities util;
		size_t next = 0;
		bool more = true;
		m_name = util.extractToken(str, next, more);
		m_product = util.extractToken(str, next, more);
		m_cntItem = 0;
		m_lstItem = nullptr;
		std::vector<string> tempItems;

		while (more) {
			std::string item = util.extractToken(str, next, more);
			if (!item.empty()) {
				tempItems.push_back(item);
				m_cntItem++;
			}
		}
		m_lstItem = new Item* [m_cntItem];
		vector<string>::iterator it = tempItems.begin();
		for (size_t i = 0; it != tempItems.end(); it++, i++) {
			m_lstItem[i] = new Item(tempItems[i]);
			m_lstItem[i]->m_itemName = *(it);
		}
		
		if (m_widthField < util.getFieldWidth()) {
			m_widthField = util.getFieldWidth();
		}
	};

	CustomerOrder::CustomerOrder(const CustomerOrder& C) {
		throw invalid_argument ("ERROR: Cannot make copies.");
	};

	CustomerOrder::CustomerOrder(CustomerOrder&& C) noexcept {
		m_cntItem = 0;
		m_lstItem = nullptr;
		operator = (move(C));
	};

	CustomerOrder& CustomerOrder::operator = (CustomerOrder&& C) noexcept {
		if (this != &C) {		
			for (size_t i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
			m_lstItem = nullptr;

			m_name = C.m_name;
			m_product = C.m_product;
			m_cntItem = C.m_cntItem;
			m_lstItem = C.m_lstItem;
			
			C.m_name = "";
			C.m_product = "";
			C.m_lstItem = nullptr;
			C.m_cntItem = 0;
		}
		return *this;
	};

	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
		m_lstItem = nullptr;
	};

	bool CustomerOrder::isOrderFilled() const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_isFilled == false) {
				return false;
			}
		}
		return (m_cntItem > 0);		
	};

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled == false) {
				return false;
			}
		}
		return true;
		
	};

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {		
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_isFilled == false) {
				string currentItemName = m_lstItem[i]->m_itemName;
				if (currentItemName == station.getItemName()) {			
					if (station.getQuantity() >= 1) {
						m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
						m_lstItem[i]->m_isFilled = true;
						station.updateQuantity();
						os << "    Filled " << m_name << ", " << m_product << " [" << currentItemName << "]" << endl;
						return;
					}
					else {
						os << "    Unable to fill " << m_name << ", " << m_product << " [" << currentItemName << "]" << endl;						
					}
				}
			}
		}	


	};

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++) {
			os << "[";
			os.width(6);
			os.fill('0'); 			
			os << m_lstItem[i]->m_serialNumber;
			os << "] ";
			os << std::setw(m_widthField);
			os.fill(' ');
			os.setf(ios::left);
			os << m_lstItem[i]->m_itemName;
			os.unsetf(ios::left);
			os << " - ";
			if (m_lstItem[i]->m_isFilled == true) {
				os << "FILLED";
			}
			else {
				os << "TO BE FILLED";
			}
			os << endl;
		}
	
	};

}