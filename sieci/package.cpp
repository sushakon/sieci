//
// Created by mawolny on 14.12.2021.
//

#include "storage_types.hpp"
#include "package.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <optional>
#include <string>


std::set<ElementID> Package::assigned_IDs = {};
std::set<ElementID> Package::freed_IDs_ = {};