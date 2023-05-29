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

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iostream>
#include <string>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"


namespace sdds
{
	extern std::deque<CustomerOrder>g_pending;
	extern std::deque<CustomerOrder>g_completed;
	extern std::deque<CustomerOrder>g_incomplete;

	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation;
	public:
		Workstation();
		Workstation(const std::string& str);
		Workstation (const Workstation& W) = delete;
		Workstation(Workstation&& W) = delete;
		Workstation& operator = (const Workstation& W) = delete;
		Workstation& operator = (Workstation&& W) = delete;
		~Workstation();
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}
#endif
