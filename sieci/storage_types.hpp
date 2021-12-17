//
// Created by mawolny on 14.12.2021.
//

#ifndef UNTITLED_STORAGE_TYPES_HPP
#define UNTITLED_STORAGE_TYPES_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <optional>
#include <list>

#include "types.hpp"
#include "package.hpp"

class IPackageStockpile
{
public:
    IPackageStockpile() {}

    std::list<Package>::const_iterator const_iterator;
    
    void push(Package&&);

    virtual ~IPackageStockpile() {}

}

class IPackageQueue(IPackageStockpile)
{
    Package pop();
    get_queue_type(); //PackageQueueType {query}
}

class PackageQueue(IPackageQueue)
{
    PackageQueue(PackageQueueType)
}

enum class PackageQueueType()
{
    FIFO;
    LIFO;
}


#endif //UNTITLED_STORAGE_TYPES_HPP