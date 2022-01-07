//
// Created by Agata on 04.01.2022.
//

#ifndef SIECI_NODES_HPP
#define SIECI_NODES_HPP

#include <map>
#include <memory>
#include "types.hpp"
#include "package.hpp"
#include "storage_types.hpp"


enum class ReceiverType {
    rampa,
    robotnik,
    magazyn
};



class IPackageReceiver
{
    public:
        virtual void receive_package(Package&& p);
        virtual ElementID get_id();
};

class Storehouse : public IPackageReceiver{

    public:

        Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d);
};

class ReceiverPreferences{

    public:
        ReceiverPreferences() = default;
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

class PackageSender: public ReceiverPreferences{

    public:

        PackageSender() = default;
        PackageSender(PackageSender&&) = default;

        void send_package();
        std::optional<Package>& get_sending_buffer();

        ReceiverPreferences receiver_preferences_;

    protected:
        void push_package(Package&& p);

};

class Ramp: PackageSender
{
    public:

        Ramp(ElementID id, TimeOffset di): id_(id), di_(di){};
        void deliver_goods(Time t);
        TimeOffset get_delivery_interval();
        ElementID get_id();

    private:
        ElementID id_;
        TimeOffset di_;

};

class Worker : public PackageSender, public IPackageReceiver
{
    public:
        Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q);

        void do_work(Time t);

        TimeOffset get_processing_duration();
        Time get_package_processing_start_time();
};





#endif //SIECI_NODES_HPP
