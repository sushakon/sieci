//
// Created by mawolny on 14.12.2021.
//

#ifndef UNTITLED_STORAGE_TYPES_HPP
#define UNTITLED_STORAGE_TYPES_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>

#include "types.hpp"
#include "package.hpp"


enum class PackageQueueType {
    FIFO,
    LIFO
};


class IPackageStockpile
{
public:
    using const_iterator = std::list<Package>::const_iterator;

    const_iterator cbegin() const { return Stockpile_.cbegin(); }
    const_iterator cend() const { return Stockpile_.cend(); }
    const_iterator begin() const { return Stockpile_.begin(); }
    const_iterator end() const { return Stockpile_.end(); }


    virtual void push(Package&& Pac) { Stockpile_.push_back(Pac); };
    virtual bool empty() const { return Stockpile_.empty(); };
    virtual size_t size() const { return Stockpile_.size(); };

    virtual ~IPackageStockpile() = default;

private:
    std::list<Package> Stockpile_;
};

class IPackageQueue : IPackageStockpile
{
public:

    virtual Package pop();

    virtual PackageQueueType get_queue_type() const;

};

class PackageQueue : IPackageQueue
{
public:
    PackageQueue(PackageQueueType) {}
};



#endif //UNTITLED_STORAGE_TYPES_HPP