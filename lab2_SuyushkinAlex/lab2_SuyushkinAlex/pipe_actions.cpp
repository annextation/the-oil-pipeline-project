#include <iostream>
#include <string>
#include <unordered_map>
#include "pipe.h"
#include "pipe_actions.h"
#include "utils.h"
#include <limits>

using namespace std;

void add_pipe(unordered_map<int, Pipe>& list_of_pipes) {
	Pipe pipe;
	cin >> pipe;
	list_of_pipes.emplace(pipe.get_id(), pipe);
}

void  veiw_all_pipes(unordered_map<int, Pipe>& list_of_pipes) {
	cout << "<" << endl;
	for (auto& pipe : list_of_pipes) {
		cout << "ID:" << pipe.first << endl << pipe.second << endl;
	}
	cout << ">" << endl;
}

void delete_pipe(unordered_map<int, Pipe>& list_of_pipes) {
	int pipe_id;
	if (list_of_pipes.empty()) {
		cout << "No pipes";
	}
	else {
		cout << "Pipe ID for deleting: " << endl << ">";
		pipe_id = GetCorrectNumber<int>(0, std::numeric_limits<int>::max());
		
		if (list_of_pipes.count(pipe_id) == 1) {
			list_of_pipes.erase(pipe_id);
		}
		else {
			cout << "No pipe with this ID." << endl;
		}
	}
}

void edit_pipe_repair(unordered_map<int, Pipe>& list_of_pipes) {
	int pipe_id;
	if (list_of_pipes.empty()) {
		cout << "No pipes";
	}
	else {
		cout << "Pipe ID for editing repair: " << endl << ">";
		pipe_id = GetCorrectNumber<int>(0, std::numeric_limits<int>::max());

		if (list_of_pipes.count(pipe_id) == 1) {
			cout << "Repair: ";
			list_of_pipes[pipe_id].set_repair(GetCorrectNumber<bool>(0, 1));
		}
		else {
			cout << "No pipe with this ID." << endl;
		}
	}
}