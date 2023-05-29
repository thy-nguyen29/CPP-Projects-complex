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
#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
	static size_t m_widthField = 0;
	static size_t id_generator = 0;

	Station::Station() {};
	Station::Station(const std::string& str) {
		size_t next = 0; 
		bool more = true; 
		Utilities util;
		m_name = util.extractToken(str, next, more); 
		if (more)m_serialNumber = std::stoi(util.extractToken(str, next, more)); 
		if (more)m_quantity = std::stoi(util.extractToken(str, next, more)); 
		
		if (m_widthField < m_name.size()) {
			m_widthField = m_name.size();
		}
		if (more)m_desc = util.extractToken(str, next, more);
		m_id = ++id_generator;
	};

	const std::string& Station::getItemName() const {
		return m_name;
	};

	size_t Station::getNextSerialNumber() {
		return m_serialNumber++;
	};

	size_t Station::getQuantity() const {
		return m_quantity;
	};

	void Station::updateQuantity() {
		if (m_quantity > 0) {
			m_quantity--;
		}
	};

	void Station::display(std::ostream& os, bool full) const {
		// id
		os.width(3);
		os.fill('0');
		os << m_id << " | ";
		
		//name
		os.width(m_widthField);
		os.setf(ios::left);
		os.fill(' ');
		os << m_name << " | ";

		//serial number
		os.width(6);
		os.setf(ios::right);
		os.fill('0');
		os << m_serialNumber << " | ";
		os.unsetf(ios::right);

		if (full) {
			os.width(4);
			os.setf(ios::right);
			os.fill(' ');
			os << m_quantity << " | ";
			os.unsetf(ios::right);
			os << m_desc;
		}
		os.unsetf(ios::left);
		os << endl;
	};
}