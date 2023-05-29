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
#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <iostream>
#include <string>

namespace sdds
{
	class Toy
	{
		unsigned int m_id;
		std::string m_toyName;
		unsigned int m_numItem;
		double m_price;
		const double hst = 0.13;
	public:
		Toy();
		Toy(const std::string& toy);
		Toy(const Toy& T);
		Toy(Toy&& T) noexcept;
		~Toy();
		Toy& operator = (const Toy& T);
		Toy& operator = (Toy&& T) noexcept;
		void update(int numItems);
		friend std::ostream& operator << (std::ostream& os, const Toy& T);

	};
	void handle(const std::string& inputString, std::string& id, std::string& name, std::string& num, std::string& price);
	void trim(std::string& str);

}






#endif
