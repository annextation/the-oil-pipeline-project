#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "kc.h"


void add_kc(std::unordered_map<int, KC>& list_of_KCs);

void veiw_all_kcs(std::unordered_map<int, KC>& list_of_KCs);

void delete_kc(std::unordered_map<int, KC>& list_of_KCs);

void edit_kc(std::unordered_map<int, KC>& list_of_KCs);