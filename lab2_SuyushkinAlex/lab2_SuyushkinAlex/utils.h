#pragma once
#include <iostream>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>

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
	//std::cerr << x << std::endl;
	return x;
}

template<typename T>
void print_selected(const std::unordered_map<int, T>& set, const std::unordered_set<int>& subset) {
	if (set.size() == 0) std::cout << "no selected" << std::endl;

	for (const int& id : subset) {
		std::cout << set.find(id)->second << std::endl;
	}
}