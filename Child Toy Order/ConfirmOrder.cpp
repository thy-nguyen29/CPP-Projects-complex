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
#include <iostream>
#include <string>
#include "ConfirmOrder.h"


using namespace std;
namespace sdds
{	
	ConfirmOrder::ConfirmOrder() {
		this->toy = nullptr;
		m_size = 0;
	};

	ConfirmOrder::ConfirmOrder(const ConfirmOrder& C) {
		operator = (C);
	};

	ConfirmOrder::ConfirmOrder( ConfirmOrder&& C) noexcept {
		operator = (move(C));
	};

	ConfirmOrder::~ConfirmOrder() {
		if (this->toy != nullptr) {
			delete[] this->toy;
			this->toy = nullptr;
			m_size = 0;
		}
	};

	ConfirmOrder& ConfirmOrder::operator = (const ConfirmOrder& C) {
		if (this != &C) {
			delete[] this->toy;
			this->toy = nullptr;
			this->toy = new const sdds::Toy * [C.m_size];
			m_size = C.m_size;
			for (size_t i = 0; i < C.m_size; i++) {
				this->toy[i] = C.toy[i];
			}
		}
		return *this;
	};

	ConfirmOrder& ConfirmOrder::operator = ( ConfirmOrder && C) noexcept{
		if (this != &C) {
			delete[] toy;
			this->toy = nullptr;

			m_size = C.m_size;
			this->toy = C.toy;
			C.toy = nullptr;
			C.m_size = 0;
		}
		return *this;
	};

	ConfirmOrder& ConfirmOrder::operator += (const sdds::Toy& toy) {
		bool found = false;
		for (size_t i = 0; i < m_size; i++)
		{
			if (this->toy[i] == &toy) {
				found = true;
				break;
			}
		}

		if (!found) {
			const sdds::Toy** temps = new const sdds::Toy * [m_size + 1];
			for (size_t i = 0; i < m_size; i++) {
				temps[i] = this->toy[i];
			}

			temps[m_size] = &toy;
			delete[] this->toy;

			this->toy = temps;
			temps = nullptr;
			m_size++;
		}
		return *this;
	};

	ConfirmOrder& ConfirmOrder::operator -= (const sdds::Toy& toy) {	
		int pos = -1;
		for (int i = 0; i < (int)m_size; i++) {
			if (this->toy[i] == &toy) {
				pos = i;
				break;
			}
		}

		if (pos != -1) {
			const sdds::Toy** temps = new const sdds::Toy * [m_size - 1];
			int i = 0;
			int j = 0;
			while (i < (int)(m_size - 1)) {
				if (j != pos) {
					temps[i] = this->toy[j];
					i++;
					j++;
				}
				else {
					this->toy[j] = nullptr;
					j++;
				}
			}

			delete[] this->toy;

			this->toy = temps;
			temps = nullptr;
			m_size--;
		}
		return *this;
	};

	std::ostream& ConfirmOrder::display(std::ostream& os) const {
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (m_size == 0) {
			os << "There are no confirmations to send!" << endl;
		}
		else {
			for (size_t i = 0; i < m_size; i++) {
				os << *(this->toy[i]);
			}
		}
		os << "--------------------------" << endl;
		return os;
	}


	std::ostream& operator << (std::ostream& os, const ConfirmOrder& C) {
		C.display(os);
		return os;
	};


}
