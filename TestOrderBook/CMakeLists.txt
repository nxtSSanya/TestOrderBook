cmake_minimum_required(VERSION 3.13)

project(OrderBook VERSION 1.0 LANGUAGES CXX)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
set(SOURCE Source.cpp benchmark.cpp OrderBookMap.cpp)
set(HEADER benchmark.h OrderBookMap.h Reverser.h)

find_package(Boost 1.80.0 COMPONENTS property_tree) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(OrderBook Source.cpp) 
    target_link_libraries(OrderBook ${Boost_LIBRARIES})
endif()
