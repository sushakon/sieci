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
#include <optional>



enum class ReceiverType {

    WORKER,
    STOREHOUSE
};


class IPackageReceiver
{
    public:

        IPackageReceiver() = default;

        virtual void receive_package(Package&& p) const = 0;
        virtual ElementID get_id() const = 0;
        virtual ReceiverType get_receiver_type() const = 0;

        virtual ~IPackageReceiver() = default;
};

class Storehouse : public IPackageReceiver{

    public:
        Storehouse() = default;
        Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d = std::make_unique<PackageQueue>(PackageQueue(PackageQueueType::FIFO))): id_(id), d_(std::move(d)){};

        void receive_package(Package&& p)const override {d_->push(std::move(p));};

        ElementID get_id() const override {return id_;};
        ReceiverType get_receiver_type()const override {return ReceiverType::STOREHOUSE;}

    private:
        ElementID id_;
        std::unique_ptr<IPackageStockpile> d_ ;
};

class ReceiverPreferences{

    public:
        ReceiverPreferences() = default;
        ReceiverPreferences(ProbabilityGenerator pg){probability_ = pg();};

        using preferences_t = std::map<IPackageReceiver*, double>;
        using const_iterator = preferences_t::const_iterator;

        const_iterator cbegin() const { return preferences_.cbegin(); };
        const_iterator cend() const { return preferences_.cend(); };
        const_iterator begin() const { return preferences_.begin(); };
        const_iterator end() const { return preferences_.end(); };

        void add_receiver(IPackageReceiver* r);
        void remove_receiver(IPackageReceiver* r);
        IPackageReceiver* choose_receiver();
        const preferences_t& get_preferences() const {return  preferences_;};


        preferences_t preferences_ ;

    private:
        double probability_ = 0;


};

class PackageSender: public ReceiverPreferences{

    public:

        PackageSender(): receiver_preferences_(), sending_buffer_(std::nullopt){};
        PackageSender(PackageSender&&) = default;

        void send_package();
        std::optional<Package>& get_sending_buffer(){return sending_buffer_;};

        ReceiverPreferences receiver_preferences_;



    protected:
        void push_package(Package&& p){sending_buffer_.emplace(p);};
        std::optional<Package> sending_buffer_ ;



};

class Ramp: public PackageSender
{
    public:

        Ramp(ElementID id, TimeOffset di): id_(id), di_(di){};
        void deliver_goods(Time t);
        TimeOffset get_delivery_interval(){return di_;};
        ElementID get_id(){return id_;};


    private:
        ElementID id_;
        TimeOffset di_;

};

class Worker : public PackageSender, public IPackageReceiver
{
    public:
        Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q = std::make_unique<PackageQueue>(PackageQueue(PackageQueueType::FIFO))):id_(id), pd_(pd), queue_(std::move(q)), start_time_(0), work_time(0){};

        void do_work(Time t);

        TimeOffset get_processing_duration(){return pd_;};
        Time get_package_processing_start_time(){return start_time_;};

        ReceiverType get_receiver_type()const override {return ReceiverType::WORKER;}

        void push_package(Package&& p);

    private:
        ElementID id_;
        TimeOffset pd_;
        std::unique_ptr<IPackageQueue> queue_ ;
        Time start_time_;
        Time work_time;
};





#endif //SIECI_NODES_HPP
