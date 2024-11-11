#pragma once
#include "pipe.h"
#include <unordered_map>
#include <unordered_set>


void ChangePipesRepair(std::unordered_map<int, Pipe>& list_of_pipes, const std::unordered_set<int>& list_of_selected_pipes);