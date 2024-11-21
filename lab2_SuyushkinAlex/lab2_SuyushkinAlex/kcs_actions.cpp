#include <iostream>
#include "kc.h"
#include "kcs_actions.h"
#include "utils.h"
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void ChangeNumberOfOperatingWorkshops(std::unordered_map<int, KC>& list_of_KCs, const std::unordered_set<int>& list_of_selected_KCs) {
	cout << "Change number of operating workshops(+ this +1, - this -1, 0 - exit): ";
	string str;
	INPUT_LINE(cin, str);
	for (const int& id : list_of_selected_KCs) {
		if (list_of_KCs.at(id).get_number_of_operating_workshops() > 1 and str == "-") {
			list_of_KCs.at(id).set_number_of_operating_workshops(list_of_KCs.at(id).get_number_of_operating_workshops() - 1);
		}
		else if (list_of_KCs.at(id).get_number_of_operating_workshops() < list_of_KCs.at(id).get_number_of_workshops() and str == "+") {
			list_of_KCs.at(id).set_number_of_operating_workshops(list_of_KCs.at(id).get_number_of_operating_workshops() + 1);
		}
		else {
			cout << "You can't change the number of id: " << id << endl;
		}
	}


}



