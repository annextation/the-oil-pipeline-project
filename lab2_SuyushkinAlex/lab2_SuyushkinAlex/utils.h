#pragma once
#include <iostream>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include "pipe.h"
#include "kc.h"

#define INPUT_LINE(in, str) getline(in>>std::ws, str); \
												std::cerr << str << std::endl;


template <typename Type>
Type GetCorrectNumber(Type min, Type max) {
	Type x;
	while ((std::cin >> x).fail()
		|| std::cin.peek() != '\n'
		|| x < min || x > max)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Enter a number of the type " << typeid(Type).name() << " in the range from " << min << " to " << max << ": ";
	}
	std::cerr << x << std::endl;
	return x;
}

template<typename T>
void print_selected(const std::unordered_map<int, T>& set, const std::unordered_set<int>& subset) {
	if (set.size() == 0) std::cout << "no selected" << std::endl;

	for (const int& id : subset) {
		std::cout << set.find(id)->second << std::endl;
	}
}

void save_in_file(const std::unordered_map<int, Pipe>& list_of_pipes, const std::unordered_map<int, KC>& list_of_KCs);
void load_from_file(std::unordered_map<int, Pipe>& list_of_pipes, std::unordered_map<int, KC>& list_of_KCs, std::unordered_set<int>& list_of_selected_pipe, std::unordered_set<int>& list_of_selected_KCs);

template<typename T>
void load(std::ifstream& file, std::unordered_map<int, T>& objs) {
	T obj(file);
	objs.emplace(obj.get_id(), obj);
}
	
template<typename T>
int get_max_id(const std::unordered_map<int, T>& objs) {
	int id = 0;
	for (auto& [k, v] : objs) {
		if (k > id) {
			id = k;
		}
	}
	return id;
}

void see_all_pipes_and_KCs(const std::unordered_map<int, Pipe>& list_of_pipes, const std::unordered_map<int, KC>& list_of_KCs);

class redirect_output_wrapper
{
	std::ostream& stream;
	std::streambuf* const old_buf;
public:
	redirect_output_wrapper(std::ostream& src)
		:old_buf(src.rdbuf()), stream(src)
	{
	}

	~redirect_output_wrapper() {
		stream.rdbuf(old_buf);
	}
	void redirect(std::ostream& dest)
	{
		stream.rdbuf(dest.rdbuf());
	}
};


template<typename T>
void delete_selected(std::unordered_map<int, T>& objs, std::unordered_set<int>& selected_objs) {
	for (const int& id : selected_objs) {
		if (objs.contains(id)) {
			objs.erase(id);
		}
	}
}