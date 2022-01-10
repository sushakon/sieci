//
// Created by Agata on 04.01.2022.
//

#include "factory.hpp"

enum class NodeColor {
    UNVISITED,
    VISITED,
    VERIFIED };



void Factory::remove_worker(ElementID id) {
    remove_receiver(ramps_list_, id);
    remove_receiver(workers_list_, id);
    workers_list_.remove_by_id(id);

}


void Factory::remove_storehouse(ElementID id) {
    remove_receiver(workers_list_, id);
    storeh_list_.remove_by_id(id);
}


bool has_reachable_storehouse(const PackageSender* sender, std::map<const PackageSender*, NodeColor>& node_colors){

    if(node_colors[sender] == NodeColor::VERIFIED)
        return true;

    node_colors[sender] = NodeColor::VISITED;

    if(sender->receiver_preferences_.get_preferences().empty()) {
        throw ExceptionForHasReachable();
    }

    bool has_other_receiver = false;

    for(const auto& it: sender->receiver_preferences_.get_preferences()){


        if(it.first->get_receiver_type() == ReceiverType::STOREHOUSE){
            has_other_receiver = true;
        }
        else if(it.first->get_receiver_type() == ReceiverType::WORKER){

            IPackageReceiver* receiver_ptr = it.first;
            auto worker_ptr = dynamic_cast<Worker*>(receiver_ptr);
            auto sd_ptr = dynamic_cast<PackageSender*>(worker_ptr);
            if(sd_ptr == sender)
                continue;

            has_other_receiver = true;

            if(node_colors[sd_ptr] == NodeColor::UNVISITED)
                has_reachable_storehouse(sd_ptr, node_colors);
        }
    }
    node_colors[sender] = NodeColor::VERIFIED;

    if(has_other_receiver){
        return true;
    }
    else{
        throw ExceptionForHasReachable();
    }
}




bool Factory::is_consistent() const {

    std::map<const PackageSender*, NodeColor> colors;

    for(auto& it: workers_list_)
        colors[(PackageSender *) &it] = NodeColor::UNVISITED;
    for(auto& it: ramps_list_)
        colors[(PackageSender* ) &it] = NodeColor::UNVISITED;
    for(auto& it: ramps_list_)
    {
        try {
            has_reachable_storehouse(&it, colors);
            return true;
        }
        catch(ExceptionForHasReachable& exception){
            return false;
        }
    }
    return true;
}

void Factory::do_deliveries(Time t) {

    for (auto &ramp : ramps_list_){
        ramp.deliver_goods(t);
    }
}


void Factory::do_package_passing() {

    for (auto &ramp : ramps_list_){
        ramp.send_package();
    }

    for (auto &worker : workers_list_){
        worker.send_package();
    }
}

void Factory::do_work(Time t) {

    for (auto &worker : workers_list_){
        worker.do_work(t);
    }
}

template<class Node>
void Factory::remove_receiver(NodeCollection<Node>& collection, ElementID id) {

    for (auto &elem: collection) {
        for(auto& it: elem.receiver_preferences_.get_preferences())

            if(it.first->get_id() == id) {
                elem.receiver_preferences_.remove_receiver(it.first);
                break;
            }
    }
}
