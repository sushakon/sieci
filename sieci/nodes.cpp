//
// Created by Agata on 04.01.2022.
//
#include "nodes.hpp"
#include <cmath>

void ReceiverPreferences::add_receiver(IPackageReceiver* r){

    int size = preferences_.size();
    size ++;
    double step = 1/size;

    for (auto it : preferences_) {

        it.second = step;
        step += step;
    }

    preferences_.insert(preferences_.cend(), {r, 1});

};

void ReceiverPreferences::remove_receiver(IPackageReceiver* r){


    preferences_.erase(r);
    int size = preferences_.size();
    double step = 1/size;

    for (auto it : preferences_) {

        it.second = step;
        step += step;
    }


};
IPackageReceiver* ReceiverPreferences::choose_receiver(){

    IPackageReceiver* receiver;


    for (auto elem : preferences_){

        if (probability_ < elem.second){
            receiver = elem.first;
            break;
        }
    }

    return receiver;

};


void PackageSender::send_package(){

    if (sending_buffer_.has_value()) {
        IPackageReceiver* receiver = choose_receiver();
        receiver->receive_package(std::move(sending_buffer_.value()));
    }
    sending_buffer_.reset();
};


void Ramp::deliver_goods(Time t) {

    if (std::fmod(t - 1 ,di_) == 0){

        Package Pac (id_);
        push_package(std::move(Pac));
    };
}

void Worker::push_package(Package&& p){

    sending_buffer_.emplace(p);
    queue_->pop();

};

void Worker::do_work(Time t) {

    if (work_time == 0){
        start_time_ = t;
    }


    if (work_time == pd_){

        Package Pac (id_);
        push_package(std::move(Pac));
        work_time = 0;
    }
    else{
        work_time++;
    }


};