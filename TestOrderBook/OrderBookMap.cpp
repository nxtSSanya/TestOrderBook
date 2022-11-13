#include "OrderBookMap.h"
#include "Reverser.h"
#include <iostream>
#include <map>

// approx - O(logN)

void DataHelper::add(double price, double amount, bool isBid) {
	if (isBid)
		bids[price] += amount;
	else
		asks[price] += amount;
}

bool DataHelper::isEmpty() const {
	return bids.empty() && asks.empty();
}

void DataHelper::add_ask(const double& price, const double& amount) {
	add(price, amount, false);
}
void DataHelper::add_bid(const double& price, const double& amount) {
	add(price, amount, true);
}

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

ostream& operator<<(ostream& os, const DataHelper& ordBook) {
	if (ordBook.isEmpty()) {
		os << "OrderBook empty\n";
		return os;
	}
	for (auto it : reverse(ordBook.asks)) {
		os << fixed << it.first << "\t" << it.second << "\n";
	}
	os << "\n\n";
	for (auto it : reverse(ordBook.bids)) {
		os << fixed << it.first << "\t" << it.second << "\n";
	}
	return os;
}