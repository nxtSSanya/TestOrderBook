#pragma once
#include <map>
#include <iostream>

class OffersListMap {
private:
	bool subscript_helper(double price) const;
public:
	OffersListMap() = default;
	double operator[](double price) const;
	double& operator[](double price);
	void MakeOffer();
	std::map<double, double> data;
};

std::ostream& operator<<(std::ostream& os, const OffersListMap& offers_list);