#include <iostream>
#include "filter.h"
#include "utils.h"

using namespace std;

bool CheckRepair(const Pipe& set, const bool repair) {
    return set.get_repair() == repair;
}


void FindByRepair(const unordered_map<int, Pipe>& set, unordered_set<int>& subset) {
    cout << "Repair: ";
    int repair = GetCorrectNumber<bool>(0, 1);

    FindByFilter<Pipe, bool>(set, subset, CheckRepair, repair);
}

bool CheckNonWorkWorshops(const KC& set, const int persent) {
    return (((set.get_number_of_workshops() - set.get_number_of_operating_workshops()) / set.get_number_of_workshops()) * 100) == persent;
}


void FindByNonWorkWorkshops(const unordered_map<int, KC> & set, unordered_set<int>& subset) {
    cout << "Persentage of non-working workshops: ";
    int persent = GetCorrectNumber<int>(0, 100);

    FindByFilter<KC, int>(set, subset, CheckNonWorkWorshops, persent);
}