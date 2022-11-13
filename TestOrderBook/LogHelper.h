#pragma once

#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

class Timer {
public:
	explicit Timer() : m_StartTimepoint(chrono::high_resolution_clock::now()) {}
	~Timer() {
		Stop();
	}
	void Stop() {
		std::ofstream log_time_out("BenchmarkingLog.txt");
		auto endTimepoint = chrono::high_resolution_clock::now();

		auto start = chrono::time_point_cast<chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = chrono::time_point_cast<chrono::microseconds>(endTimepoint).time_since_epoch().count();

		auto duration = end - start;
		double ms = duration * 0.001;
		log_time_out << msg << " " << ms << " microseconds\n";
	}
	std::string msg;
private:
	chrono::time_point <chrono::high_resolution_clock> m_StartTimepoint;
};
