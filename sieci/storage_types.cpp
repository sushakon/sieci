//
// Created by mawolny on 14.12.2021.
//

#include "storage_types.hpp"
#include "package.hpp"

#include<iostream>
#include<vector>
#include <algorithm>
#include <stack>
#include <optional>
#include <string>

void IPackageQueue::pop()
{
	const_iterator iterator;

	switch (Package_.type_)
	{
	case PackageQueueType::FIFO:
		iterator = Package_.Stockpile_.cbegin();
		Package_.Stockpile_.pop_front();

	case PackageQueueType::LIFO:
		iterator = Package_.Stockpile_.cend();
		Package_.Stockpile_.pop_back();
	}

	Package::freed_IDs_.insert((*iterator).get_id());
	Package::assigned_IDs.erase((*iterator).get_id());
}

