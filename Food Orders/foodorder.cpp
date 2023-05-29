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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "foodorder.h"

 double g_taxrate;
 double g_dailydiscount;

using namespace std;
namespace sdds
{
	FoodOrder::FoodOrder() {
		m_price = 0;
		m_dailySpecial = false;
	};

	FoodOrder::FoodOrder(const FoodOrder& F) {
		strcpy(this->m_name, F.m_name);
		this->m_foodDesc = new char [strlen(F.m_foodDesc) + 1];
		strcpy(this->m_foodDesc, F.m_foodDesc);
		this->m_price = F.m_price;
		this->m_dailySpecial = F.m_dailySpecial;
		
	};

	FoodOrder& FoodOrder::operator =(const FoodOrder& F) {
		if (this != &F) {
			strcpy(this->m_name, F.m_name);
			delete[] this->m_foodDesc;
			this->m_foodDesc = nullptr;
			this->m_foodDesc = new char[strlen(F.m_foodDesc) + 1];
			strcpy(this->m_foodDesc, F.m_foodDesc);
			this->m_price = F.m_price;
			this->m_dailySpecial = F.m_dailySpecial;
		}
		return *this;
	};

	FoodOrder::~FoodOrder() {
		delete[] this->m_foodDesc;
		this->m_foodDesc = nullptr;
	};

	std::istream& FoodOrder::read(std::istream& is) {
		char dailySpecial = '\0';
		string foodDesc;
		string name;

		if (is.good()) {
			getline(is, name, ',');
			if (name != "") {
				strcpy(m_name, name.c_str());
				getline(is, foodDesc, ',');
				m_foodDesc = new char[foodDesc.length() + 1]; // foodDes.length() + 1
				strcpy(m_foodDesc, foodDesc.c_str());
				is >> m_price;
				is.ignore();
				is >> dailySpecial;
				is.ignore(1000, '\n');
				is.clear();
				if (dailySpecial == 'N') {
					this->m_dailySpecial = false;
				}
				else {
					this->m_dailySpecial = true;
				}
			}	
		}
		return is;

	};

	void FoodOrder::display() {
		static int counter = 0;
	
			counter++;
			cout.width(2);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << counter << ". ";
			cout.unsetf(ios::left);

			if (strcmp(m_name, "") == 0) {
				cout << "No Order" << endl;
				delete[] m_foodDesc;
				m_foodDesc = nullptr;
				return;
			}
			cout.width(10);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_name << '|';
			cout.unsetf(ios::left);

			cout.width(25);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_foodDesc << '|';
			cout.unsetf(ios::left);

			cout.width(12);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << fixed << std::setprecision(2);
			cout << (m_price + m_price*g_taxrate) << '|';
			cout.unsetf(ios::left);

			if (m_dailySpecial) {
				cout.width(13);
				cout.fill(' ');
				cout.setf(ios::right);
				cout << fixed << std::setprecision(2);
				cout << (m_price + m_price * g_taxrate) - g_dailydiscount;
				cout.unsetf(ios::right);
			}
			cout << endl;
		
	};

}