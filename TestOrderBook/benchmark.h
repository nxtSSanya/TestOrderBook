#pragma once

#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

typedef std::chrono::time_point<std::chrono::steady_clock> time_point_t;
typedef long double microseconds_t;

class Benchmark {
public:
	void start();
	void end();
	microseconds_t getMicros();
private:
	time_point_t m_startTime;
	time_point_t m_endTime;
	microseconds_t m_ellapsedTime;
};
