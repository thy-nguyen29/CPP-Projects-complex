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
#include "Utilities.h"
#include "Workstation.h"

using namespace std;
namespace sdds
{

	Workstation::Workstation() {
		m_pNextStation = nullptr;
	};

	Workstation::Workstation(const string& str) : Station(str) {
		m_pNextStation = nullptr;	
	};

	Workstation::~Workstation() {};

	void Workstation::fill(std::ostream& os) {
		if (!m_orders.empty()) {
			m_orders.front().fillItem(*this, os);
		}
	};

	bool Workstation::attemptToMoveOrder() {
		if (!m_orders.empty()) {
			CustomerOrder& ref = m_orders.front();
			if (ref.isItemFilled(this->getItemName()) == true || this->getQuantity() == 0) {
				if (this->getNextStation() == nullptr) {
					if (ref.isOrderFilled() == true) {
						g_completed.push_back(move(ref));
					}
					else {
						g_incomplete.push_back(move(ref));
					}
				}
				else {
					(*(this->m_pNextStation)) += std::move(ref);
				}
				m_orders.pop_front();
				return true;
			}
		}
		return false;
	};

	void Workstation::setNextStation(Workstation* station) {
		m_pNextStation = station;
	};
	
	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	};
	
	void Workstation::display(std::ostream& os) const {
		if (m_pNextStation == nullptr) {
			os << getItemName() << " --> End of Line" << endl;
		}
		else {
			os << getItemName() << " -->" << getNextStation() << endl;
		}
	};
	
	Workstation& Workstation::operator += (CustomerOrder&& newOrder) {
		this->m_orders.push_back(move(newOrder));
		return *this;
	};
}

