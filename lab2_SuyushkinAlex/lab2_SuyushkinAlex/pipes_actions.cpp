#include <iostream>
#include "pipe.h"
#include "pipes_actions.h"
#include "utils.h"
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void ChangePipesRepair(std::unordered_map<int, Pipe>& list_of_pipes, const std::unordered_set<int>& list_of_selected_pipes) {
	cout << "Input new repair: " ;
	bool new_repair = GetCorrectNumber<bool>(0, 1);
	for (const int& id : list_of_selected_pipes) {
		list_of_pipes.find(id)->second.set_repair(new_repair);
	}
}