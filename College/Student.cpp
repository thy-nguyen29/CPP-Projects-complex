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
#include <iostream>
#include <string>
#include "Student.h"
#include "Utilities.h"


using namespace std;
namespace sdds
{
	Student::Student() {
		m_name = '\0';
		m_id = '\0';
		m_courses = nullptr;
		m_age = 0;
		m_count = 0;
	};

	Student::~Student() {
		delete[] m_courses;
		m_courses = nullptr;
	};

	Student::Student(std::istream& is) {
		string name, age, id, courseNum;
		getline(is, name, ',');
		removeSpace(name);
		this->m_name = name;

		getline(is, age, ',');
		removeSpace(age);
		for (size_t i = 0; i < age.size(); i++) {
			if (!isdigit(age[i])) {
				throw name + "++Invalid record!";
			}
		}
		this->m_age = stoi(age);

		getline(is, id, ',');
		removeSpace(id);
		if (id[0] != 'S') {
			throw name + "++Invalid record!";
		}
		this->m_id = id;

		getline(is, courseNum, ',');
		removeSpace(courseNum);
		for (size_t i = 0; i < courseNum.size(); i++) {
			if (!isdigit(courseNum[i])) {
				throw name + "++Invalid record!";
			}
		}
		this->m_count = stoi(courseNum);

		m_courses = new string[m_count];
		for (size_t i = 0; i < m_count - 1; i++) {
			getline(is, m_courses[i], ',');
			removeSpace(m_courses[i]);
		}
		getline(is, m_courses[m_count - 1], '\n');
		removeSpace(m_courses[m_count - 1]);
	
	};
	
	
	std::string Student::status() const {
		return "Student";
	};

	std::string Student::name() const {
		return m_name;
	};

	std::string Student::age() const {
		return to_string(m_age);
	};

	std::string Student::id() const {
		return m_id;
	};



	void Student::display(std::ostream& out) const {
		out.setf(ios::left);
		out << "| ";

		//---status---
		out.width(10);
		out.fill(' ');
		out << status();

		//---id---
		out << "| ";
		out.width(10);
		out.fill(' ');
		out << this->m_id;

		//---name---
		out << "| ";
		out.width(20);
		out.fill(' ');
		out << this->m_name;

		//---age---
		out << " | ";
		out.width(3);
		out.fill(' ');
		out << this->m_age << " |";

		for (size_t i = 0; i < m_count - 1; i++) {
			out << m_courses[i] << ", ";
		}
		out << m_courses[m_count - 1];
	
	};


}
