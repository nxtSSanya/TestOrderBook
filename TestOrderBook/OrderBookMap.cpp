#include "OrderBookMap.h"
#include <iostream>
#include <map>

// approx - O(logN)
// Ya ebnutiy AHHAHAHAHHAAHAH

bool OffersListMap::subscript_helper(double price) const
{
	if (!isfinite(price)) {
		throw "Price shouldn't be inf or NaN";
	}
	return data.find(price) != data.end();
}
double OffersListMap::operator[](double price) const {
	if (!subscript_helper(price)) {
		return 0;
	}
	return data.at(price);
}

double& OffersListMap::operator[](double price) {
	subscript_helper(price);
	return data[price];
}
void OffersListMap::MakeOffer() {
	for (auto it = data.begin(); it != data.end();) {
		if (!it->second) {
			it = data.erase(it);
		}
		else {
			++it;
		}
	}
}

//std::ostream& operator<<(std::ostream& os, const OffersListMap& offers_list) {
//	bool is_first = true;
//	for (auto [price, amount] : reverse(offers_list.data)) {
//		if (!is_first) { cout << endl; }
//		if (is_first) { is_first = false; }
//		std::cout << std::fixed << price << " | " << amount;
//	}
//	return os;
//}
