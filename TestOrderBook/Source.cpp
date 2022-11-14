#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "OrderBookMap.h"
#include <chrono>
#include "benchmark.h"

using std::cout;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    boost::property_tree::ptree pt;
    std::ifstream json_in("huobi.json");
    if (!json_in) {
        std::cout << "No file \"huobi.json\" in current directory.\n";
        system("pause");
    }
    std::cout << "Working...\n";
    std::ofstream log_out("BenchmarkLog.txt");
    std::ofstream result("results.txt");
    std::string line_json; 

    DataHelper list_map;
    Benchmark timer;

    while (std::getline(json_in, line_json)) {

        long double time_bid = 0;
        long double time_ask = 0;
        line_json = line_json.substr(62, line_json.size() - 1);
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

            timer.start();
            list_map.add_bid(price, amount);
            timer.end();
            time_bid = timer.getNanos();
        }

        for (auto& array2 : pt.get_child("asks")) {
            double price = 0.0, amount = 0.0;
            double* const elements[2] = { &price, &amount };
            auto it = std::begin(elements);

            for (auto& i : array2.second) {
                **it++ = i.second.get_value<double>();
                if (it == std::end(elements)) break;
            }

            timer.start();
            list_map.add_ask(price, amount);
            timer.end();
            time_ask = timer.getNanos();
        }

        log_out << "Update:\t\t" << time_bid + time_ask << " nanoseconds\n";
        list_map.MakeOffer();

        timer.start();
        list_map.getBestBid();
        list_map.getBestAsk();
        timer.end();
        log_out << "Get best:\t\t" << timer.getNanos() << " nanoseconds\n";

        result << "{" << pt.get<std::string>("event_time") << "}, {" << fixed << list_map.getBestBid().first << "}, {" 
            << list_map.getBestBid().second << "}, {" << list_map.getBestAsk().first << "}, {" << list_map.getBestAsk().second << "}\n";
    }
}
