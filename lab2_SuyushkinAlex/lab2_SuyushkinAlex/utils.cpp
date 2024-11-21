#include <iostream>
#include "pipe.h"
#include "pipes_actions.h"
#include "kcs_actions.h"
#include "utils.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void save_in_file(const unordered_map<int, Pipe>& list_of_pipes, const unordered_map<int, KC>& list_of_KCs) {
    string file_name;

    cout << "Input file name: ";
    cin.ignore();
    INPUT_LINE(cin, file_name);

    ofstream file(file_name);

    if (file.is_open()) {
        if (list_of_pipes.empty()) {
            cout << "No pipes" << endl;
        }
        else {
            for (auto& [id,pipe]: list_of_pipes) {
 
                pipe.save(file);
            }
        }

        if (list_of_KCs.empty()) {
            cout << "No KCs" << endl;
        }
        else {
            for (auto& [id,cs] : list_of_KCs) {

                cs.save(file);
            }
        }

        file.close();
    }
    else {
        cout << "Error" << endl;
    }

}

void load_from_file(std::unordered_map<int, Pipe>& list_of_pipes, std::unordered_map<int, KC>& list_of_KCs, std::unordered_set<int>& list_of_selected_pipes, std::unordered_set<int>& list_of_selected_KCs) {
    string file_name;

    cout << "Input file name: ";
    cin.ignore();
    INPUT_LINE(cin, file_name);
    ifstream file(file_name);

    if (file.is_open()) {
        list_of_pipes.clear();
        list_of_selected_pipes.clear();
        list_of_KCs.clear();
        list_of_selected_KCs.clear();

        string line;

        while (file >> line) {
            if (line == "Pipe") {
                load(file, list_of_pipes);
            }

            if (line == "KC") {
                load(file, list_of_KCs);
            }
        }

        file.close();
        Pipe::set_max_id(list_of_pipes);
        KC::set_max_id(list_of_KCs);

    }
    else {
        cout << "Error" << endl;
    }

}

void see_all_pipes_and_KCs(const unordered_map<int, Pipe>& list_of_pipes, const unordered_map<int, KC>& list_of_KCs) {
    if (list_of_pipes.empty()) {
        cout << "No pipes" << endl;
    }
    else {
        for (auto& pipe : list_of_pipes) {
            cout << pipe.second << endl;
        }
    }

    if (list_of_KCs.empty()) {
        cout << "No KCs" << endl;
    }
    else {
        for (auto& KC : list_of_KCs) {
            cout << KC.second << endl;
        }
    }
}