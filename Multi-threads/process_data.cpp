// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant

#include<thread>
#include "process_data.h"


namespace sdds_ws9 {

	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {
			avg += arr[i];
		}
		avg /= divisor;
	}

	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}
	ProcessData::operator bool() const {
		return total_items > 0 && data && num_threads>0 && averages && variances && p_indices;
	}

	ProcessData::ProcessData(std::string filename, int n_threads) {  
		std::ifstream file(filename, std::ios::binary);
		data = nullptr;
		if (!file.is_open()) {
			throw std::runtime_error("Can't open file");
			return;
		}

		file.read((char*)&total_items, sizeof(int));

		data = new int[total_items];
		file.read((char*)&data[0], total_items * sizeof(int));
		file.close();

		std::cout << "Item's count in file '"<< filename << "': " << total_items << std::endl;
		std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
		          << data[total_items - 3] << ", " << data[total_items - 2] << ", "
		          << data[total_items - 1] << "]\n";

		num_threads = n_threads; 
		averages = new double[num_threads] {};
		variances = new double[num_threads] {};
		p_indices = new int[num_threads+1] {};
		for (int i = 0; i < num_threads+1; i++)
			p_indices[i] = i * (total_items / num_threads);
	}
	ProcessData::~ProcessData() {
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}

	int ProcessData::operator()(std::string filename, double& avg, double& var) {
		auto AvgFactor = std::bind(computeAvgFactor, std::placeholders::_1, std::placeholders::_2, total_items, std::placeholders::_3);
		std::vector<std::thread> threads(num_threads);
		
		for (int i = 0; i < num_threads; i++) {
			threads[i] = std::thread(AvgFactor, &data[p_indices[i]], p_indices[i + 1] - p_indices[i], std::ref(averages[i]));
		}

		for (auto& thread : threads) {
			thread.join();
		}

		for (int i = 0; i < num_threads; i++) {
			avg += averages[i];
		}


		auto varFactor = std::bind(computeVarFactor, std::placeholders::_1, std::placeholders::_2, total_items, avg, std::placeholders::_3);		
		for (int i = 0; i < num_threads; i++) {
			threads[i] = std::thread(varFactor, &data[p_indices[i]], std::move(p_indices[i + 1] - p_indices[i]), std::ref(variances[i]));
		}

		for (auto& thread : threads) {
			thread.join();
		}

		for (int i = 0; i < num_threads; i++) {
			var += variances[i];
		}

		std::ofstream outfile(filename, std::ios::binary);

		if (!outfile) {
			throw std::runtime_error("Error: File cannot be written\n");
			return 1;
		}
		outfile.write((const char*)&total_items, sizeof(total_items));
		outfile.write((const char*)data, sizeof(int) * total_items);

		outfile.close();

		return 0;
	};
}

