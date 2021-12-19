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

Package IPackageQueue::pop()
{
	if (get_queue_type() == FIFO)
	{

	}
	else if(get_queue_type() == LIFO)
	{

	}

}

PackageQueueType IPackageQueue::get_queue_type() const
{
	return PackageQueueType();
}
