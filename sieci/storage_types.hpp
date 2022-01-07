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

    IPackageStockpile() = default;

    using const_iterator = std::list<Package>::const_iterator;

    const_iterator cbegin() const { return Stockpile_.cbegin(); };
    const_iterator cend() const { return Stockpile_.cend(); };
    const_iterator begin() const { return Stockpile_.begin(); };
    const_iterator end() const { return Stockpile_.end(); };

    virtual void push(Package&& Pac) { Stockpile_.emplace_back(Pac); };
    virtual bool empty() const { return Stockpile_.empty(); };
    virtual size_t size() const { return Stockpile_.size(); };


    std::list<Package> Stockpile_ = {};
    virtual ~IPackageStockpile() = default;

};

class IPackageQueue : public IPackageStockpile
{
public:

    IPackageQueue() = default;

    virtual void pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0;


};

class PackageQueue : public IPackageQueue
{
public:
    PackageQueue() = default;
    PackageQueue(PackageQueueType type): type_(type){};

    PackageQueueType get_queue_type() const override {return type_;}
    void pop() override;

private:
    PackageQueueType type_;
};

#endif //UNTITLED_STORAGE_TYPES_HPP