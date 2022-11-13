#pragma once
#include <map>
#include <iostream>

using namespace std;

class DataHelper {
public:
	DataHelper() = default;

    std::map<double, double> bids;
    std::map<double, double> asks;

    void MakeOffer();
    std::pair<double, double> getBestBid();
    std::pair<double, double> getBestAsk();
};

std::ostream& operator<<(std::ostream& os, const std::map < double, double> &offers_list);