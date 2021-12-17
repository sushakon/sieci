//
// Created by mawolny on 14.12.2021.
//

#ifndef UNTITLED_STORAGE_TYPES_HPP
#define UNTITLED_STORAGE_TYPES_HPP

#endif //UNTITLED_STORAGE_TYPES_HPP

class IPackageStockpile()
{
    push(Package&&) : void
    empty() : bool {query}
    size() : size_type {query}
    /iteratory/
    ~IPackageStockpile()

}

class IPackageQueue(IPackageStockpile)
{
    pop() : Package
    get_queue_type() : PackageQueueType {query}
}

class PackageQueue(IPackageQueue)
{
    PackageQueue(PackageQueueType)
}

enum class PackageQueueType()
{
    FIFO
    LIFO
}