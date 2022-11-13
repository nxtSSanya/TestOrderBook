#include "benchmark.h"

void Benchmark::start() {
	m_startTime = std::chrono::high_resolution_clock::now();
}

void Benchmark::end() {
	m_endTime = std::chrono::high_resolution_clock::now();

	m_ellapsedTime = (nanoseconds_t)std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime).count();
}

nanoseconds_t Benchmark::getNanos() {
	return m_ellapsedTime;
}

