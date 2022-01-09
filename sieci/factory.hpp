//
// Created by Agata on 04.01.2022.
//

#ifndef SIECI_FACTORY_HPP
#define SIECI_FACTORY_HPP


#include <map>
#include <memory>
#include "nodes.hpp"
#include "types.hpp"
#include "package.hpp"
#include "storage_types.hpp"
#include <optional>
#include <mmcobj.h>

template <class T>
class mypair {
    T values [2];
public:
    mypair (T first, T second)
    {
        values[0]=first; values[1]=second;
    }
};
class NodeCollection{

    void add(Node&& node);
    void remove_by_id(ElementID id);
    NodeCollection<Node>::iterator find_by_id(ElementID id);
    NodeCollection<Node>::const_iterator find_by_id(ElementID id);

    /iteratory
};

class Factory{

    public:
        void add_ramp(Ramp&&){};
        void remove_ramp(ElementID id);
        NodeCollection<Ramp>::iterator find_ramp_by_id(ElementID id);

        NodeCollection<Ramp>::const_iterator find_ramp_by_id(ElementID id);

        NodeCollection<Ramp>::const_iterator ramp_cbegin();
        NodeCollection<Ramp>::const_iterator ramp_cend();
        NodeCollection<Ramp>::const_iterator ramp_begin();
        NodeCollection<Ramp>::const_iterator ramp_end();

        NodeCollection<Worker>::const_iterator Worker_cbegin();
        NodeCollection<Worker>::const_iterator Worker_cend();
        NodeCollection<Worker>::const_iterator Worker_begin();
        NodeCollection<Worker>::const_iterator Worker_end();

        bool is_consistent();
        void do_deliveries(Time);
        void do_package_passing();
        void do_work(Time);

    private:
        void remove_receiver(NodeCollection<Node>& collection, ElementID id);
};

#endif //SIECI_FACTORY_HPP
