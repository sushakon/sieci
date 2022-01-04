//
// Created by mawolny on 14.12.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <optional>
#include <string>

#include "package.hpp"
#include "types.hpp"


std::set<ElementID> Package::assigned_IDs = {};
std::set<ElementID> Package::freed_IDs_ = {};