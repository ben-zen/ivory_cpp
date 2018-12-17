cmake_minimum_required(VERSION 3.7)
set (CMAKE_PREFIX_PATH /usr/lib/x86_64-linux-gnu/cmake/)
project (Tutorial)

find_package(Boost COMPONENTS system REQUIRED)
find_package(cpprestsdk REQUIRED)

add_executable(Tutorial basic_client.cc)

target_link_libraries(Tutorial PRIVATE cpprestsdk::cpprest)
target_link_libraries(Tutorial PRIVATE Boost::system)