//
// Created by Agata on 04.01.2022.
//
#include "nodes.hpp"

void ReceiverPreferences::add_receiver(IPackageReceiver* r){

//    int size = preferences_.size();
//    size ++;
//    double step = 1/size;
//
//    for (auto it : preferences_) {
//
//        it.second = step;
//        step += step;
//    }

};

void ReceiverPreferences::remove_receiver(IPackageReceiver* r){

    double multiplier = 1/(1 - preferences_[r]);
    preferences_.erase(r);

    for (auto it = begin(); it != end(); ++it){

        preferences_[it->first] = it->second * multiplier;
    }


};
IPackageReceiver* ReceiverPreferences::choose_receiver(){

    IPackageReceiver* receiver;
    double sum = cbegin()->second;

    for (auto it = begin(); it != end(); ++it){

        if (probability_ < sum){

        }
    }

    return receiver;

};