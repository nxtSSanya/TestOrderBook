#include <iostream>
#include <string>
#include "OrderBookMap.h"
#include "LogHelper.h"

using namespace std;

void benchmark_insert(
	int		int_part_min,
	int		int_part_max,
	int		decimal_part_min,
	int		decimal_part_max,
	int		amount_min,
	int		amount_max,
	int		ops_count,
	const string& msg
){
	{
		LOG_DURATION(to_string(ops_count) + " Inserts. " + msg + " (Map)", ops_count)
			OffersListMap offers_list;
		for (int i = 0; i < ops_count; ++i) {
			//offers_list[dist_int_part(gen) + static_cast<double>(dist_decimal_part(gen)) / decimal_part_max] = dist_amount(gen);
		}
	}
}

void		run_benchamrk()
{
	benchmark_insert(0, 100,
		0, 10,
		0, 1000,
		1'000, "Small range. Small decimal range");
	benchmark_insert(0, 100,
		0, 10,
		0, 1000,
		100'000,
		"Small range. Small decimal range");
	benchmark_insert(0, 100,
		0, 10,
		0, 1000,
		1'000'000,
		"Small range. Small decimal range");
	benchmark_insert(0, 100,
		0, 10,
		0, 1000,
		10'000'000,
		"Small range. Small decimal range");
	cerr << endl;
	benchmark_insert(0, 10000,
		0, 10,
		0, 1000,
		1'000, "Big range. Small decimal range");
	benchmark_insert(0, 10000,
		0, 10,
		0, 1000,
		100'000, "Big range. Small decimal range");
	benchmark_insert(0, 10000,
		0, 10,
		0, 1000,
		1'000'000,
		"Big range. Small decimal range");
	benchmark_insert(0, 10000,
		0, 10,
		0, 1000,
		10'000'000,
		"Big range. Small decimal range");
	cerr << endl;
	benchmark_insert(0, 100,
		0, 10000,
		0, 1000,
		1'000, "Small range. Big decimal range");
	benchmark_insert(0, 100,
		0, 10000,
		0, 1000,
		100'000, "Small range. Big decimal range");
	benchmark_insert(0, 100,
		0, 10000,
		0, 1000,
		1'000'000,
		"Small range. Big decimal range");
	benchmark_insert(0, 100,
		0, 10000,
		0, 1000,
		10'000'000,
		"Small range. Big decimal range");
	cerr << endl;
	benchmark_insert(0, 10000,
		0, 10000,
		0, 1000,
		1'000, "Big range. Big decimal range");
	benchmark_insert(0, 10000,
		0, 10000,
		0, 1000,
		100'000, "Big range. Big decimal range");
	benchmark_insert(0, 10000,
		0, 10000,
		0, 1000,
		1'000'000,
		"Big range. Big decimal range");
	benchmark_insert(0, 10000,
		0, 10000,
		0, 1000,
		10'000'000,
		"Big range. Big decimal range");
	cerr << endl << endl;
}