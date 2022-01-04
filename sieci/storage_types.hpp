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

    const_iterator cbegin() const { return Package_.Stockpile_.cbegin(); }
    const_iterator cend() const { return Package_.Stockpile_.cend(); }
    const_iterator begin() const { return Package_.Stockpile_.begin(); }
    const_iterator end() const { return Package_.Stockpile_.end(); }


    virtual void push(Package&& Pac) { Package_.Stockpile_.emplace_back(Pac); };
    virtual bool empty() const { return Package_.Stockpile_.empty(); };
    virtual size_t size() const { return Package_.Stockpile_.size(); };

    virtual ~IPackageStockpile() = default;

private:
    PackageQueue Package_;
};

class IPackageQueue : private IPackageStockpile
{
public:

    virtual void pop();

    virtual PackageQueueType get_queue_type() const { return Package_.type_; };

private:
    PackageQueue Package_;

};

class PackageQueue : IPackageQueue
{
public:
    PackageQueue(PackageQueueType type, std::list<Package> list = {}) : type_(type), Stockpile_(list) {};

    PackageQueueType type_;
    std::list<Package> Stockpile_;
};


#endif //UNTITLED_STORAGE_TYPES_HPP