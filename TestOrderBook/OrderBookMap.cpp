#include "OrderBookMap.h"
#include "Reverser.h"
#include <iostream>
#include <map>

// approx - O(logN)

void DataHelper::MakeOffer() {
	for (auto it = asks.begin(); it != asks.end();) {
		if (it->second == 0.0) {
			it = asks.erase(it);
		}
		else {
			++it;
		}
	}
	for (auto it = bids.begin(); it != bids.end();) {
		if (it->second == 0.0) {
			it = bids.erase(it);
		}
		else {
			++it;
		}
	}
}

std::pair<double, double> DataHelper::getBestBid() {
	return std::make_pair(bids.rbegin()->first, bids.rbegin()->second);
}

std::pair<double, double> DataHelper::getBestAsk() {
	return std::make_pair(asks.begin()->first, asks.begin()->second);
}

ostream& operator<<(ostream& os, const std::map <double, double>& offers_list) {
	bool is_first = true;
	for (auto it : reverse(offers_list)) {
		if (!is_first) { cout << endl; }
		if (is_first) { is_first = false; }
		cout << fixed << it.first << "\t" << it.second;
	}
	std::cout << "\n";
	return os;
}