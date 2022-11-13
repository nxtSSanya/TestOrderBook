cmake_minimum_required(VERSION 3.13)

project(OrderBook VERSION 1.0 LANGUAGES CXX)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)
find_package(boost COMPONENTS property_tree REQUIRED) 

include_directories(${Boost_INCLUDE_DIRS})

add_executable(OrderBook Source.cpp benchmark.cpp OrderBookMap.cpp benchmark.h OrderBookMap.h Reverser.h) 
target_link_libraries(OrderBook ${Boost_LIBRARIES})