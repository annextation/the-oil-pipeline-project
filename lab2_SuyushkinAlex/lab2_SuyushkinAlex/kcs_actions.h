#pragma once
#include "kc.h"
#include <unordered_map>
#include <unordered_set>


void ChangeNumberOfOperatingWorkshops(std::unordered_map<int, KC>& list_of_KCs, const std::unordered_set<int>& list_of_selected_KCs);
