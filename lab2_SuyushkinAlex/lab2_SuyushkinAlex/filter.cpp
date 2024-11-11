#include <iostream>
#include "filter.h"
#include "utils.h"

using namespace std;

bool CheckRepair(const Pipe& pipe, const bool repair) {
    return pipe.get_repair() == repair;
}


void FindByRepair(const std::unordered_map<int, Pipe>& pipes, std::unordered_set<int>& selected_pipes) {
    cout << "working status(0 - no / 1 - yes): ";
    int repair = GetCorrectNumber<int>(0, 1);

    FindByFilter<Pipe, bool>(pipes, selected_pipes, CheckRepair, repair);
}

