#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include "pipe.h"
#include "utils.h"
#include "pipe_actions.h"
#include "kc_actions.h"
#include "filter.h"
#include "menu.h"
#include <chrono>
#include <format>

using namespace std;
using namespace chrono;

int main()
{	

	redirect_output_wrapper cerr_out(cerr);
	string time = std::format("{:%d_%m_%Y %H_%M_%OS}", system_clock::now());
	ofstream logfile("log_" + time);
	if (logfile)
		cerr_out.redirect(logfile);

	unordered_map<int, Pipe> list_of_pipes;
	unordered_set<int> list_of_selected_pipes;

	unordered_map<int, KC> list_of_KCs;
	unordered_set<int> list_of_selected_KCs;
	
	int input;
	do {
		print_main_menu();
		input = GetCorrectNumber<int>(0, 5);

		switch (input) {
		case 1:
			pipe_menu(list_of_pipes, list_of_selected_pipes);
			break;
		case 2:
			kc_menu(list_of_KCs, list_of_selected_KCs);
			break;
		case 3:
			see_all_pipes_and_KCs(list_of_pipes, list_of_KCs);
			break;
		case 4:
			save_in_file(list_of_pipes, list_of_KCs);
			break;
		case 5:
			load_from_file(list_of_pipes, list_of_KCs, list_of_selected_pipes, list_of_selected_KCs);
			break;
		}
	} while (input != 0);
};