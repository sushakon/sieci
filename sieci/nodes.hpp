//
// Created by Agata on 04.01.2022.
//

#ifndef SIECI_NODES_HPP
#define SIECI_NODES_HPP

#include <map>
#include "types.hpp"


enum class ReceiverType {
    rampa,
    robotnik,
    magazyn
};



class IPackageReceiver
{

};

class Storehouse : IPackageReceiver{

};

class ReceiverPreferences{

public:
    ReceiverPreferences(ProbabilityGenerator pg){probability_ = pg();};

    using preferences_t = std::map<IPackageReceiver*, double>;
    using const_iterator = preferences_t::const_iterator;

    const_iterator cbegin() const { return preferences_.cbegin(); }
    const_iterator cend() const { return preferences_.cend(); }
    const_iterator begin() const { return preferences_.begin(); }
    const_iterator end() const { return preferences_.end(); }

    void add_receiver(IPackageReceiver* r);
    void remove_receiver(IPackageReceiver* r);
    IPackageReceiver* choose_receiver();
    preferences_t& get_preferences(){return preferences_;};


    preferences_t preferences_ ;

private:
    double probability_ = 0;


};

class PackageSender: ReceiverPreferences{
};

class Ramp: PackageSender
{

};

class Worker : PackageSender, IPackageReceiver
{

};





#endif //SIECI_NODES_HPP
