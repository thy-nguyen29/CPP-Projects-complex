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
#include <cstddef>
#include <chrono>
#include "TimedTask.h"


using namespace std;
namespace sdds
{
	TimedTask::TimedTask() {
		m_records = 0;
	};

	void TimedTask::startClock() {
		startTime = std::chrono::steady_clock::now();
	};

	void TimedTask::stopClock() {
		endTime = std::chrono::steady_clock::now();
	};
	void TimedTask::addTask(const char* taskName) {
		if (m_records < MAX_EVENT_NUM) {
			task[m_records].m_taskName = taskName; //string = cstring
			task[m_records].m_timeUnit = "nanoseconds";
			task[m_records].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
			m_records++;
		}
	};

	std::ostream& operator << (std::ostream& os, const TimedTask& T) {// <<:insertion ; >>: extraction
		os << "--------------------------\n";
		os << "Execution Times:\n";
		os << "--------------------------\n";
		for (int i = 0; i < T.m_records; i++) {
			os.width(21);
			os.setf(ios::left);
			os << T.task[i].m_taskName;
			os.unsetf(ios::left);

			os.width(13);
			os.setf(ios::right);
			os << T.task[i].duration.count();
			os.unsetf(ios::right);
			os << " ";
			os << T.task[i].m_timeUnit << '\n';

		}
		os << "--------------------------\n";
		return os;
	};


}