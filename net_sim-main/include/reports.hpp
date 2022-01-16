//
// Created by Agata on 04.01.2022.
//

#ifndef REPORTS_HPP
#define REPORTS_HPP

#include "nodes.hpp"
#include "factory.hpp"

void generate_structure_report(Factory& f, std::ostream& os);

void generate_simulation_turn_report(Factory& f, std::ostream& os, Time t);


#endif //REPORTS_HPP
