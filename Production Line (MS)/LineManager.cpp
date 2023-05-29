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
#include <fstream>
#include <algorithm>
#include "Station.h"
#include "LineManager.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
	std::deque<CustomerOrder> g_pending;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;

	LineManager::LineManager() {
		m_cntCustomerOrder = 0;
		m_firstStation = nullptr;
	};

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		Utilities util;
		ifstream ifs(file);
		if (ifs.is_open()) {
			std::string line;
			size_t next_pos = 0;
			bool more = true;
			vector<bool> marked(stations.size(), false);
			while (getline(ifs, line, '\n')) {
				std::string current_ws = util.extractToken(line, next_pos, more);
				if (!more) {
					m_activeLine.push_back(nullptr);
					auto it = std::find_if(stations.begin(), stations.end(), [=](const Workstation* ws) {
						return ws->getItemName() == current_ws;
						});
					(*it)->setNextStation(nullptr);
				}
				else {
					std::string next_ws = util.extractToken(line, next_pos, more);
					auto it1 = std::find_if(stations.begin(), stations.end(), [=](const Workstation* ws) {
						return ws->getItemName() == current_ws;
						});
					auto it2 = std::find_if(stations.begin(), stations.end(), [=](const Workstation* ws) {
						return ws->getItemName() == next_ws;
						});
					(*it1)->setNextStation(*it2);
					m_activeLine.push_back(*it2);
					marked[std::distance(stations.begin(), it2)] = true;
				}
			}
			ifs.close();
			auto it = std::find_if(marked.begin(), marked.end(), [](bool b) {
				return b == false;
				});
			if (it != marked.end()) {
				m_firstStation = stations[std::distance(marked.begin(), it)];
			}
			m_cntCustomerOrder = g_pending.size();
		}
	};

	void LineManager::reorderStations() {
		Workstation* cur = m_firstStation;
		for (size_t i = 0; i < m_activeLine.size() - 1; i++) {
			cur = cur->getNextStation();
			int id = -1;
			for (size_t j = i + 1; j < m_activeLine.size(); j++) {
				if (m_activeLine[j] == cur) {
					id = j;
					break;
				}
			}
			if (id != -1) {
				Workstation* temp = m_activeLine[i];
				m_activeLine[i] = m_activeLine[id];
				m_activeLine[id] = temp;
			}
		}
	};

	bool LineManager::run(std::ostream& os) {
		static size_t count = 0;
		count++;
		os << "Line Manager Iteration : " << count << endl;
		if (!g_pending.empty()) {
			*m_firstStation += move(g_pending.front());
			g_pending.pop_front();
		}
		// first loop to fill
		Workstation* cur = m_firstStation;
		while (cur != nullptr) {
			cur->fill(os);
			cur = cur->getNextStation();
		}
		cur = m_firstStation;
		while (cur != nullptr) {
			cur->attemptToMoveOrder();
			cur = cur->getNextStation();
		}
		return m_cntCustomerOrder == (g_completed.size() + g_incomplete.size());
	};

	void LineManager::display(std::ostream& os) const {
		for (auto activeStation : m_activeLine) {
			Workstation* cur = m_firstStation;
			while (cur != nullptr) {
				if (cur->getNextStation() == activeStation) {
					break;
				}
				cur = cur->getNextStation();
			}

			if (activeStation == nullptr) {
				os << cur->getItemName() << " --> End of Line" << endl;
			}
			else {
				os << cur->getItemName() << " --> " << activeStation->getItemName() << endl;
			}
		}
	};













}