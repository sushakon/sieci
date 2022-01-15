//
// Created by Agata on 04.01.2022.
//

#ifndef NETSIM_REPORTS_HPP
#define NETSIM_REPORTS_HPP

#include "nodes.hpp"
#include "factory.hpp"

void generate_structure_report(Factory& f, std::ostream& os);

void generate_simulation_turn_report(Factory& f, std::ostream& os, Time t);


#endif //NETSIM_REPORTS_HPP
