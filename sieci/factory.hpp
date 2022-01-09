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

template <class Node>
class NodeCollection{

    public:
        using container_t = typename std::list<Node>;
        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;

        void add(Node&& node);
        void remove_by_id(ElementID id);
        NodeCollection<Node>::iterator find_by_id(ElementID id);
        NodeCollection<Node>::const_iterator find_by_id(ElementID id);

        NodeCollection<Node>::const_iterator _cbegin() { return container_t.cbegin(); };
        NodeCollection<Node>::const_iterator _cend() { return container_t.cend(); };
        NodeCollection<Node>::const_iterator _begin() { return container_t.begin(); };
        NodeCollection<Node>::const_iterator _end() { return container_t.end(); };
   };

class Factory{

    public:
        void add_ramp(Ramp&&){};
        void remove_ramp(ElementID id);
        NodeCollection<Ramp>::iterator find_ramp_by_id(ElementID id);

        NodeCollection<Ramp>::const_iterator find_ramp_by_id(ElementID id);

        NodeCollection<Ramp>::const_iterator ramp_cbegin() { return NodeCollection<Ramp>::_cbegin(); };
        NodeCollection<Ramp>::const_iterator ramp_cend();

        void add_worker(Worker&&) {};
        void remove_worker(ElementID id);
        NodeCollection<Worker>::iterator find_worker_by_id(ElementID id);

        NodeCollection<Worker>::const_iterator find_worker_by_id(ElementID id);

        NodeCollection<Worker>::const_iterator worker_cbegin();
        NodeCollection<Worker>::const_iterator worker_cend();

        void add_storehouse(Storehouse&&) {};
        void remove_storehouse(ElementID id);
        NodeCollection<Storehouse>::iterator find_storehouse_by_id(ElementID id);

        NodeCollection<Storehouse>::const_iterator find_storehouse_by_id(ElementID id);

        NodeCollection<Storehouse>::const_iterator storehouse_cbegin();
        NodeCollection<Storehouse>::const_iterator storehouse_cend();


        bool is_consistent();
        void do_deliveries(Time);
        void do_package_passing();
        void do_work(Time);

    private:
        void remove_receiver(NodeCollection<Node>& collection, ElementID id);
};

#endif //SIECI_FACTORY_HPP
