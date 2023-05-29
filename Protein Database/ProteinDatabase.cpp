/*
*****************************************************************************
						  Workshop - #2 - Part2
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NDD
Completed date: Jan 26, 2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "ProteinDatabase.h"
#include <chrono>

using namespace std;
namespace sdds
{
	ProteinDatabase::ProteinDatabase() {
		m_string = nullptr;
		stringCt = 0;
	};

	ProteinDatabase::ProteinDatabase(const char* filename) {
		ifstream ifs(filename); // FILE* fptr;
		string str; //current line is read
		string protein_str;
		int proteinCount = 0;
		if (ifs.is_open() && ifs.good()) {
			while (!ifs.eof()) {
				getline(ifs, str);
				if (str[0] == '>') {
					proteinCount++;
				}
			}
			m_string = new string[proteinCount];
		}
		ifs.close();
		stringCt = proteinCount;

		proteinCount = -1;
		ifs.open(filename);
		if (ifs.is_open()) {
			while (!ifs.eof())
			{
				getline(ifs, str);
				if (str[0] == '>') {
					if (proteinCount != -1) {
						m_string[proteinCount] = protein_str; //add new protein string to m_string;
					}
					proteinCount++;
					protein_str = ""; //reset protein_str;
				}
				else {
					protein_str += str;
				}
			}

			m_string[proteinCount] = protein_str;
			proteinCount++;
			ifs.close();
		}
	};

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& P) {

			this->m_string = new string[P.stringCt];
			for (int i = 0; i < P.stringCt; i++) {
				this->m_string[i] = P.m_string[i];
			}
			this->stringCt = P.stringCt;
	};

	ProteinDatabase::ProteinDatabase (ProteinDatabase&& P) noexcept {  // move constructor		
			m_string = nullptr;
			this->m_string = P.m_string;
			P.m_string = nullptr;
			this->stringCt = P.stringCt;
			P.stringCt = 0;
	};

	ProteinDatabase::~ProteinDatabase() {
		delete[] m_string;
		m_string = nullptr;
		stringCt = 0;
	};

	ProteinDatabase& ProteinDatabase::operator = (const ProteinDatabase& P) {
		if (this != &P) {
			delete[] m_string;
			m_string = nullptr;

			this->m_string = new string[P.stringCt];
			for (int i = 0; i < P.stringCt; i++) {
				this->m_string[i] = P.m_string[i];
			}
			this->stringCt = P.stringCt;
		}
		return *this;
	};

	ProteinDatabase& ProteinDatabase::operator = (ProteinDatabase&& P) noexcept {  //move operator
		if (this != &P) {
			delete[] m_string;
			m_string = nullptr;
			this->m_string = P.m_string;
			P.m_string = nullptr;
			this->stringCt = P.stringCt;
			P.stringCt = 0;
		}
		return *this;
	
	};

	size_t ProteinDatabase::size() {
		return stringCt;
	};
	std::string ProteinDatabase::operator[](size_t i) {

		if (i < 0 || i > std::size_t(stringCt - 1) || stringCt == 0) {
			return "";
		}
		return m_string[i];
	};


}