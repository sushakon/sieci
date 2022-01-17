//
// Created by Agata on 04.01.2022.
//

#ifndef REPORTS_HPP
#define REPORTS_HPP

#include "nodes.hpp"
#include "factory.hpp"

void generate_structure_report(Factory& f, std::ostream& os);

void generate_simulation_turn_report(Factory& f, std::ostream& os, Time t);


class IntervalReportNotifier {
private:
    TimeOffset to_;
public:
    explicit IntervalReportNotifier(TimeOffset to) : to_(to) {}
    bool  should_generate_report(Time t) { return (t - 1) % to_ == 0; }
};

class SpecificTurnsReportNotifier {
private:
    std::set<Time> turns_;
public:
    explicit SpecificTurnsReportNotifier(std::set<Time> turns) : turns_(std::move(turns)) {}
    bool should_generate_report(Time t) { return turns_.find(t) != turns_.end(); }
};



#endif //REPORTS_HPP
