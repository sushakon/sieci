//
// Created by mawolny on 14.12.2021.
//

#ifndef UNTITLED_PACKAGE_HPP
#define UNTITLED_PACKAGE_HPP

#include <set>

class Package {
public:
    Package() {

        if (not freed_IDs_.empty()) {
            id_ = *freed_IDs_.cbegin();
            freed_IDs_.erase(0);
        }
        else {
            ElementID el = *assigned_IDs.cend()++;
            id_ = el;
            assigned_IDs.insert(el);
        }
    };

    Package(ElementID id) { id_ = id; };
    Package(Package&& Pac) = default;

    Package& operator = (Package&& Pac);

    ElementID get_id() const { return id_; };

    ~Package() = default;

private:
    std::size_t id_ = 0;
    inline static std::set<ElementID> assigned_IDs = {};
    inline static std::set<ElementID> freed_IDs_ = {};

};

#endif //UNTITLED_PACKAGE_HPP