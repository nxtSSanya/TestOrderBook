#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "OrderBookMap.h"
#include <chrono>

using std::cout;
using std::endl;

int main() {

    boost::property_tree::ptree pt;
    std::ifstream json_in("outfile.json");
    std::string line_json; 

    std::vector<std::pair<double, double> > v;
    OffersListMap list_map;
    
    while (std::getline(json_in, line_json)) {

        std::stringstream ss;
        ss << line_json;

        boost::property_tree::read_json(ss, pt);
        {
            //std::cout << pt.get<std::string>("type") << std::endl;
            //cout << pt.get<std::string>("event_time") << endl;
        }
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        //read bids
        for (auto& array2 : pt.get_child("bids")) {
            double first = 0.0, second = 0.0;
            double* const elements[2] = { &first, &second };
            auto element = std::begin(elements);

            for (auto& i : array2.second) {
                **element++ = i.second.get_value<double>();
                if (element == std::end(elements)) break;
            }
            //v.push_back({ first, second });
            list_map[first] = second;
        }

        for (auto& array2 : pt.get_child("asks")) {
            double first = 0.0, second = 0.0;
            double* const elements[2] = { &first, &second };
            auto element = std::begin(elements);

            for (auto& i : array2.second) {
                **element++ = i.second.get_value<double>();
                if (element == std::end(elements)) break;
            }
            //v.push_back({ first, second });
            list_map[first] = second;
        }

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        cout << "Time for creating map: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " ms" << endl;
        cout.precision(3);
        //for (auto& i : v) cout << std::fixed << i.first << " " << i.second << endl;
        for (auto& i : list_map.data) cout << std::fixed << i.first << " " << i.second << endl;
        cout << "---------------------------" << endl;
    }
}