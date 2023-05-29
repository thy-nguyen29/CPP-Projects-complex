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
#ifndef SDDS_TIMEDTASK_H
#define	SDDS_TIMEDTASK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>

namespace sdds
{
	class TimedTask
	{
		static const int MAX_EVENT_NUM = 10;

		int m_records;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;

		struct Task
		{
			std::string m_taskName;
			std::string m_timeUnit;
			std::chrono::steady_clock::duration duration;
		}task[MAX_EVENT_NUM];

	public:

		TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char* taskName);
		friend std::ostream& operator << (std::ostream& os, const TimedTask& T);

	};

}

#endif