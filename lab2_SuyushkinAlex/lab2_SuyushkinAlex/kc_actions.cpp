#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>
#include <fstream>
#include "kc.h"
#include "kc_actions.h"
#include "utils.h"

using namespace std;

void add_kc(unordered_map<int, KC>& list_of_KCs) {
	KC kc;
	cin >> kc;
	list_of_KCs.emplace(kc.get_id(), kc);
}

void  veiw_all_kcs(unordered_map<int, KC>& list_of_KCs) {
	cout << "<";
	for (auto& kc : list_of_KCs) {
		cout << kc.second << endl;
	}
	cout << ">";
}

void delete_kc(unordered_map<int, KC>& list_of_KCs) {
	int kc_id;
	if (list_of_KCs.empty()) {
		cout << "No kcs" << endl;
	}
	else {
		cout << "KC ID for deleting: " << endl << ">";
		kc_id = GetCorrectNumber<int>(0, std::numeric_limits<int>::max());

		if (list_of_KCs.count(kc_id) == 1) {
			list_of_KCs.erase(kc_id);
		}
		else {
			cout << "No kc with this ID." << endl;
		}
	}
}

void edit_kc(unordered_map<int, KC>& list_of_KCs) {
	int kc_id;
	string input;
	if (list_of_KCs.empty()) {
		cout << "No kcs";
	}
	else {
		cout << "KC ID for editing number of operating workshops: " << endl << ">";
		kc_id = GetCorrectNumber<int>(0, std::numeric_limits<int>::max());

		if (list_of_KCs.count(kc_id) == 1) {
			while (1) {
				cout << "Number of operating workshops(+ = +1, - = -1), p.s. 0 - exit: ";
				INPUT_LINE(cin, input);
				if (input == "+" && list_of_KCs[kc_id].get_number_of_operating_workshops() < list_of_KCs[kc_id].get_number_of_workshops()) {
					list_of_KCs[kc_id].set_number_of_operating_workshops(list_of_KCs[kc_id].get_number_of_operating_workshops() + 1); 
 				}
				else if (input == "-" && list_of_KCs[kc_id].get_number_of_operating_workshops() <= list_of_KCs[kc_id].get_number_of_workshops() && list_of_KCs[kc_id].get_number_of_operating_workshops() > 0) {
					list_of_KCs[kc_id].set_number_of_operating_workshops(list_of_KCs[kc_id].get_number_of_operating_workshops() - 1);
				}
				else if (input == "0") {
					break;
				}
				else {
					std::cout << "number of operating workshops must be in range(0, " << list_of_KCs[kc_id].get_number_of_workshops() << ")" << endl;
				}
			}
		}
		else {
			cout << "No kc with this ID." << endl;
		}
	}
}