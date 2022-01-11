cmake_minimum_required(VERSION 3.20)
project(sieci)

set(CMAKE_CXX_STANDARD 14)

include_directories(netsim_tests/include)
include_directories(netsim_tests/mocks)
include_directories(sieci)

add_executable(sieci
        netsim_tests/include/config.hpp
        netsim_tests/mocks/global_functions_mock.hpp
        netsim_tests/mocks/nodes_mocks.hpp
        netsim_tests/test/main_gtest.cpp
        netsim_tests/test/test_Factory.cpp
        netsim_tests/test/test_factory_io.cpp
        netsim_tests/test/test_nodes.cpp
        netsim_tests/test/test_package.cpp
        netsim_tests/test/test_reports.cpp
        netsim_tests/test/test_simulate.cpp
        netsim_tests/test/test_storage_types.cpp
        sieci/factory.cpp
        sieci/factory.hpp
        sieci/helpers.cpp
        sieci/helpers.hpp
        sieci/nodes.cpp
        sieci/nodes.hpp
        sieci/package.cpp
        sieci/package.hpp
        sieci/storage_types.cpp
        sieci/storage_types.hpp
        sieci/types.hpp
        main.cpp)
