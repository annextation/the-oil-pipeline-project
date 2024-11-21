#include <iostream>
#include "pipe.h"
#include "pipe_actions.h"
#include "kc.h"
#include "kc_actions.h"
#include "menu.h"
#include "utils.h"
#include "filter.h"
#include "pipes_actions.h"
#include "kcs_actions.h"
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <format>

using namespace std;

void print_main_menu() {
	cout << "-----------------------------" << endl;
	cout << "1. Actions with the pipe" << endl;
	cout << "2. Actions with the CS" << endl;
	cout << "3. View all objects" << endl;
	cout << "4. Save in file" << endl;
	cout << "5. Load from file" << endl;
	cout << "0. Exit" << endl;
	cout << "-----------------------------" << endl;
	cout << "> ";
};

void print_pipe_menu() {
	cout << "-----------------------------" << endl;
	cout << "1. Add a pipe" << endl;
	cout << "2. Delete a pipe" << endl;
	cout << "3. Edit a pipe" << endl;
	cout << "4. View all pipes" << endl;
	cout << "5. Filter" << endl;
	cout << "0. Exit" << endl;
	cout << "-----------------------------" << endl;
	cout << "> ";
}

void print_filter_pipe() {
	cout << "-----------------------------" << endl;
	cout << "1. Select all pipes" << endl;
	cout << "2. Select by ID" << endl;
	cout << "3. Select by name" << endl;
	cout << "4. Select by repair" << endl;
	cout << "5. Actions with selected pipes" << endl;
	cout << "0. Exit" << endl;
	cout << "-----------------------------" << endl;
	cout << "> ";
}

void filter_pipe(unordered_map<int, Pipe>& list_of_pipes, unordered_set<int>& list_of_selected_pipes) {
	int input;
	do {
		print_filter_pipe();
		input = GetCorrectNumber<int>(0, 5);
		switch (input) {
		case 1:
			SelectAll(list_of_pipes, list_of_selected_pipes);
			break;
		case 2:
			list_of_selected_pipes = SelectByID(list_of_pipes);
			break;
		case 3:
			FindByName(list_of_pipes, list_of_selected_pipes);
			break;
		case 4:
			FindByRepair(list_of_pipes, list_of_selected_pipes);		
			break;
		case 5:
			select_pipes_menu(list_of_pipes, list_of_selected_pipes);
			break;
		}
	} while (input != 0);
}

void print_select_pipes_menu() {
	cout << "-----------------------------" << endl;
	cout << "1. See selected pipes" << endl;
	cout << "2. Change repair" << endl;
	cout << "3. Select selected by ID" << endl;
	cout << "4. Delete selected" << endl;
	cout << "0. Exit" << endl;
	cout << "-----------------------------" << endl;
	cout << "> ";
}

void select_pipes_menu(unordered_map<int, Pipe>& list_of_pipes, unordered_set<int>& list_of_selected_pipes) {
	int input;
	do {
		print_select_pipes_menu();
		input = GetCorrectNumber(0, 8);
		switch (input) {
		case 1:
			print_selected(list_of_pipes, list_of_selected_pipes);
			break;

		case 2:
			ChangePipesRepair(list_of_pipes, list_of_selected_pipes);
			break;
		case 3:
			list_of_selected_pipes = SelectByID(list_of_selected_pipes);
			break;
		case 4:
			delete_selected(list_of_pipes, list_of_selected_pipes);
			break;
		}
	} while (input != 0);
}


void pipe_menu(unordered_map<int, Pipe>& list_of_pipes, unordered_set<int>& list_of_selected_pipes) {
	int input;
	do {
		print_pipe_menu();
		input = GetCorrectNumber<int>(0, 8);

		switch (input) {
		case 1:
			add_pipe(list_of_pipes);
			break;

		case 2:
			delete_pipe(list_of_pipes);
			break;

		case 3:
			edit_pipe_repair(list_of_pipes);
			break;

		case 4:
			veiw_all_pipes(list_of_pipes);
			break;

		case 5:
			filter_pipe(list_of_pipes, list_of_selected_pipes);
			break;
		}
	} while (input != 0);
}


void print_filter_kc() {
	cout << "-----------------------------" << endl;
	cout << "1. Select all kcs" << endl;
	cout << "2. Select by ID" << endl;
	cout << "3. Select by name" << endl;
	cout << "4. Select by % of non-working workshops" << endl;
	cout << "5. Actions with selected kcs" << endl;
	cout << "0. Exit" << endl;
	cout << "-----------------------------" << endl;
	cout << "> ";
}

void filter_kc(unordered_map<int, KC>& list_of_KCs, unordered_set<int>& list_of_selected_KCs) {
	int input;
	do {
		print_filter_kc();
		input = GetCorrectNumber<int>(0, 5);
		switch (input) {
		case 1:
			SelectAll(list_of_KCs, list_of_selected_KCs);
			break;
		case 2:
			list_of_selected_KCs = SelectByID(list_of_KCs);
			break;
		case 3:
			FindByName(list_of_KCs, list_of_selected_KCs);
			break;
		case 4:
			FindByNonWorkWorkshops(list_of_KCs, list_of_selected_KCs);
			break;
		case 5:
			select_kcs_menu(list_of_KCs, list_of_selected_KCs);
			break;
		}
	} while (input != 0);
}


void print_select_kcs_menu() {
	cout << "-----------------------------" << endl;
	cout << "1. See selected kcs" << endl;
	cout << "2. Change number of operating workshops" << endl;
	cout << "3. Select selected by ID" << endl;
	cout << "4. Delete selecred" << endl;
	cout << "0. Exit" << endl;
	cout << "-----------------------------" << endl;
	cout << "> ";
}

void select_kcs_menu(unordered_map<int, KC>& list_of_KCs, unordered_set<int>& list_of_selected_KCs) {
	int input;
	do {
		print_select_kcs_menu();
		input = GetCorrectNumber(0, 3);
		switch (input) {
		case 1:
			print_selected(list_of_KCs, list_of_selected_KCs);
			break;

		case 2:
			ChangeNumberOfOperatingWorkshops(list_of_KCs, list_of_selected_KCs);
			break;
		case 3:
			list_of_selected_KCs = SelectByID(list_of_selected_KCs);
			break;
		case 4:
			delete_selected(list_of_KCs, list_of_selected_KCs);
		}
	} while (input != 0);
}

void print_kc_menu() {
	cout << "-----------------------------" << endl;
	cout << "1. Add a KC" << endl;
	cout << "2. Delete a KC" << endl;
	cout << "3. Edit a KC" << endl;
	cout << "4. View all KCs" << endl;
	cout << "5. Filter" << endl;
	cout << "0. Exit" << endl;
	cout << "-----------------------------" << endl;
	cout << "> ";
}

void kc_menu(unordered_map<int, KC>& list_of_KCs, unordered_set<int>& list_of_selected_KCs) {
	int input;
	do {
		print_kc_menu();
		input = GetCorrectNumber<int>(0, 5);

		switch (input) {
		case 1:
			add_kc(list_of_KCs);
			break;

		case 2:
			delete_kc(list_of_KCs);
			break;

		case 3:
			edit_kc(list_of_KCs);
			break;

		case 4:
			veiw_all_kcs(list_of_KCs);
			break;

		case 5:
			filter_kc(list_of_KCs, list_of_selected_KCs);
			break;
		}
	} while (input != 0);
}