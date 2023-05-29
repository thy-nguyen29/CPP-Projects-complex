/*
*****************************************************************************
						  Workshop - #6 - part2
Full Name     : Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NDD
Completed date: Mar 03, 2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Utilities.h"

using namespace std;
namespace sdds
{
	Person* buildInstance(std::istream& in) {
		Person* p = nullptr;
		std::string tag;
		getline(in, tag, ',');
		if (tag == "e" || tag == "E") {
			p = new sdds::Employee(in);
		}
		else if (tag == "p" || tag == "P") {
			p = new sdds::Professor(in);
		}
		else {
			p = new sdds::Student(in);
		}
		return p;
	};

	void removeSpace(std::string& str) {
		size_t i = 0;
		while (str[i] == ' ') {
			str.erase(i, 1);
		}
		i = str.size() - 1;
		while (str[i] == ' ') {
			str.erase(i, 1);
			i = str.size() - 1;
		}
	};
}