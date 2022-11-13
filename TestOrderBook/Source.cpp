#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "OrderBookMap.h"
#include <chrono>
#include "LogHelper.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    boost::property_tree::ptree pt;
    std::ifstream json_in("outfile.json");
    std::ofstream log_out("BenchmarkLog.txt");
    std::ofstream result("results.txt");
    std::string line_json; 

    DataHelper list_map;

    while (std::getline(json_in, line_json)) {

        long long time_bid = 0;
        long long time_ask = 0;
        std::stringstream ss;

        ss << line_json;
        cout.precision(8);
        boost::property_tree::read_json(ss, pt);

        for (auto& array2 : pt.get_child("bids")) {
            double price = 0.0, amount = 0.0;
            double* const elements[2] = { &price, &amount };
            auto it = std::begin(elements);

            for (auto& i : array2.second) {
                **it++ = i.second.get_value<double>();
                if (it == std::end(elements)) break;
            }

            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            list_map.add_bid(price, amount);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            time_bid = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        }

        for (auto& array2 : pt.get_child("asks")) {
            double price = 0.0, amount = 0.0;
            double* const elements[2] = { &price, &amount };
            auto it = std::begin(elements);

            for (auto& i : array2.second) {
                **it++ = i.second.get_value<double>();
                if (it == std::end(elements)) break;
            }

            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            list_map.add_ask(price, amount);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            time_ask = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        }

        log_out << "Update:\t\t" << time_bid + time_ask << " microseconds\n";
        list_map.MakeOffer();

        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        list_map.getBestBid();
        list_map.getBestAsk();
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        log_out << "Get best:\t\t" << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds\n";

        result << "{" << pt.get<std::string>("event_time") << "}, {" << fixed << list_map.getBestBid().first << "}, {" 
            << list_map.getBestBid().second << "}, {" << list_map.getBestAsk().first << "}, {" << list_map.getBestAsk().second << "}\n";
        
        cout << list_map;
    }
}