#include "benchmark.h"

void Benchmark::start() {
	m_startTime = std::chrono::high_resolution_clock::now();
}

void Benchmark::end() {
	m_endTime = std::chrono::high_resolution_clock::now();

	m_ellapsedTime = (microseconds_t)std::chrono::duration_cast<std::chrono::microseconds>(m_endTime - m_startTime).count();
}

microseconds_t Benchmark::getMicros() {
	return m_ellapsedTime;
}

