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
        using container_t = typename std_container_t<Node>;
        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;

        void add(Node&& node);
        void remove_by_id(ElementID id);
        NodeCollection<Node>::iterator find_by_id(ElementID id);
        NodeCollection<Node>::const_iterator find_by_id(ElementID id);
   };

class Factory{

    public:
        void add_ramp(Ramp&&){};
        void remove_ramp(ElementID id);
        NodeCollection<Ramp>::iterator find_ramp_by_id(ElementID id);

        NodeCollection<Ramp>::const_iterator find_ramp_by_id(ElementID id);

        NodeCollection<Ramp>::const_iterator ramp_cbegin();
        NodeCollection<Ramp>::const_iterator ramp_cend();

        NodeCollection<Worker>::const_iterator worker_cbegin();
        NodeCollection<Worker>::const_iterator worker_cend();

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
