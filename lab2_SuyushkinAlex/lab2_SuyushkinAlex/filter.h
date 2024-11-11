#pragma once
#include "pipe.h"
#include "kc.h"
#include "utils.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>


template<typename T, typename K>
using Filter = bool(*)(const T& set, const K param);

template<typename T>
std::unordered_set<int> SelectByID(const T& set) {
	std::unordered_set<int> subset;
	int id;
	while (1) {
		std::cout << "Input ID, p.s. 0 - finish the selection: ";
		id = GetCorrectNumber(0, 1000);
		if (id == 0) {
			return subset;
		}
		if (set.count(id) == 1) {
			subset.emplace(id);
		}
		else  if ((set.count(id) != 1)){
			std::cout << "Pipe with this ID is not defined." << std::endl;
		}
	}
}

template<typename T, typename K>
bool CheckByName(const T& set, const K name) {
	return set.get_name().find(name) != std::string::npos;
}

template<typename T, typename K>
void  FindByFilter(const std::unordered_map<int, T>& set, std::unordered_set<int>& subset, Filter<T, K> func, const K param) {
	for (const auto& set : set) {
		if (func(set.second, param) == 1) {
			subset.emplace(set.first);
		}
	}
}

template<typename T>
void FindByName(const std::unordered_map<int, T>& set, std::unordered_set<int>& subset) {
	std::string name;
	std::cout << "Input a name to searh for: ";
	std::cin.ignore();
	std::getline(std::cin, name);

	FindByFilter(set, subset, CheckByName, name);
}

bool CheckRepair(const Pipe& pipe, const bool is_working);


void FindByRepair(const std::unordered_map<int, Pipe>& pipes, std::unordered_set<int>& selected_pipes);

template<typename T>
void SelectAll(const std::unordered_map<int, T>& set, std::unordered_set<int>& subset) {
	for (const auto& set : set) {
		subset.emplace(set.first);
	}
}

