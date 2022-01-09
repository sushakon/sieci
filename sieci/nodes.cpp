//
// Created by Agata on 04.01.2022.
//
#include "nodes.hpp"

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

void Worker::push_package(Package&& p){


};
