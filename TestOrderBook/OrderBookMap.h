#pragma once
#include <map>
#include <iostream>

using namespace std;

class DataHelper {
    std::map<double, double> bids;
    std::map<double, double> asks;
    void add(double price, double amount, bool isBid);

public:
    DataHelper() = default;
    bool isEmpty() const;
    void add_ask(const double& price, const double& amount);
    void add_bid(const double& price, const double& amount);
    void MakeOffer();
    std::pair<double, double> getBestBid();
    std::pair<double, double> getBestAsk();
    friend std::ostream& operator<<(std::ostream& os, const DataHelper& ordBook);
};

