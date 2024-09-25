#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Pipe {
	string name; 
	int lenght;
	int diameter;
	bool repair;
};

struct KC {
	string name;
	int number_of_workshops;
	int number_of_operating_workshops;
	float effectiveness;
};

void print_menu() {
	//system("cls");
	cout << "1. Add a pipe" << endl;
	cout << "2. Add a CS" << endl;
	cout << "3. View all objects" << endl;
	cout << "4. Edit the pipe" << endl;
	cout << "5. Edit the CS" << endl;
	cout << "6. Save" << endl;
	cout << "7. Upload" << endl;
	cout << "0. Exit" << endl;
	cout << "> ";
};


void clear(){
	cin.clear();
	cin.ignore(100, '\n');
};

int input_number(int a, int b) {
	int number;

	while (1) {
		cin >> number;

		if (cin.fail()) {
			clear();
			cout << "Incorrect input, try again." << endl;
			continue;
		};

		if (number < a || number > b) {
			cout << "Incorrect input, try again." << endl;
			continue;
		}

		break;
	};
	return number;
};

string input_string() {
	string str;

	for (;;) {
		cin.ignore(100, '\n');
		getline(cin, str);

		if (!str.empty()) {
			return str;
		}
	}
};

int input_int() {
	int integer;

	while (1) {
		cin >> integer;

		if (cin.fail() || integer < 0) {
			clear();
			cout << "Incorrect input, try again." << endl;
			continue;
		};

		break;
	};

	return integer;
};

float input_float() {
	float flt;

	while (1) {
		cin >> flt;

		if (cin.fail() || flt < 0) {
			clear();
			cout << "Incorrect input, try again." << endl;
			continue;
		};

		break;
	};

	return flt;
};

bool input_bool() {
	bool boo;

	while (1) {
		cin >> boo;

		if (cin.fail()) {
			clear();
			cout << "Incorrect input, try again." << endl;
			continue;
		};

		break;
	};

	return boo;
};

void input_pipe_characteristics(Pipe& pipe1) {
	
	cout << "pipe name > ";
	pipe1.name = input_string();
	cout << "pipe lenght > ";
	pipe1.lenght = input_int();
	cout << "pipe diameter > ";
	pipe1.diameter = input_int();
	cout << "pipe repair > ";
	pipe1.repair = input_bool();

}

void input_kc_characteristics(KC& kc1) {
	
	cout << "kc name > ";
	kc1.name = input_string();
	cout << "kc number_of_workshops > ";;
	kc1.number_of_workshops = input_int();
	cout << "kc number_of_operating_workshops > ";
	kc1.number_of_operating_workshops = input_int();
	while (kc1.number_of_workshops < kc1.number_of_operating_workshops) {
		cout << "number_of_workshops < number_of_operating_workshops, try again" << endl;
		kc1.number_of_operating_workshops = input_int();
	}
	cout << "kc effectiveness > ";
	kc1.effectiveness = input_float();

}

void print_pipe(const Pipe& pipe1) {
	cout << "PIPE:" << endl <<
		"Pipe name: " << pipe1.name << endl <<
		"Pipe lenght: " << pipe1.lenght << endl <<
		"Pipe diameter: " << pipe1.diameter << endl <<
		"Pipe repair: " << pipe1.repair << endl;
}

void print_kc(const KC& kc1) {
	cout << "KC:" << endl <<
		"KC name: " << kc1.name << endl <<
		"KC number_of_workshops: " << kc1.number_of_workshops << endl <<
		"KC number_of_operating_workshops: " << kc1.number_of_operating_workshops << endl <<
		"KC effectiveness >: " << kc1.effectiveness << endl;
}

void view_all_objects(const Pipe& pipe1, const KC& kc1) {///

	if (pipe1.name == "No name") {
		cout << "Pipe is not defined." << endl;
	}
	else {
		print_pipe(pipe1);
	};

	if (kc1.name == "No name") {
		cout << "KC is not defined." << endl;
	}
	else {
		print_kc(kc1);
	};
};

void edit_the_pipe(Pipe& pipe1) {
	if (!(pipe1.name == "No name")) {
		cout << "pipe repair > ";
		pipe1.repair = input_bool();
	}
	else {
		cout << "Pipe is not defined." << endl;
	}
};

void edit_the_kc(KC& kc1) {
	if (!(kc1.name == "No name")) {
		cout << "pipe repair > ";
		kc1.effectiveness = input_bool();
	}
	else {
		cout << "KC is not defined." << endl;
	}
};

void write_in_file_pipe(const Pipe& pipe1, ofstream& file) {///////
	file << "PIPE:" << endl <<
		pipe1.name << endl <<
		pipe1.lenght << endl <<
		pipe1.diameter << endl <<
		pipe1.repair << endl;
	
}

void write_in_file_kc(const KC& kc1, ofstream& file) {//////
	file << "KC:" << endl <<
		kc1.name << endl <<
		kc1.number_of_workshops << endl <<
		kc1.number_of_operating_workshops << endl <<
		kc1.effectiveness << endl;
}

void write_in_file(Pipe& pipe1, KC& kc1) {
	ofstream file;
	file.open("test.txt");
	if (!file.is_open()) {
		cout << "file error";
	}
	else {
		if (!(pipe1.name == "No name")) {
			write_in_file_pipe(pipe1, file);
		}
		if (!(kc1.name == "No name")) {
			write_in_file_kc(kc1, file);
		}
	}
}

void read_from_file_pipe(Pipe& pipe1, ifstream& file) {
	getline(file ,pipe1.name);
	file >> pipe1.lenght;
	file >> pipe1.diameter;
	file >> pipe1.repair;
}
void read_from_file_kc(KC& kc1, ifstream& file) {
	getline(file, kc1.name);
	file >> kc1.number_of_workshops;
	file >> kc1.number_of_operating_workshops;
	file >> kc1.effectiveness;
}

void read_from_file(Pipe& pipe1, KC& kc1) {
	string line;
	ifstream file;
	file.open("test.txt");
	if (!file.is_open()) {
		cout << "file error";
		return;
	}
	
	while (getline(file, line)) {
		if (line == "PIPE:") {
			read_from_file_pipe(pipe1, file);
		}

		if (line == "KC:") {
			read_from_file_kc(kc1, file);
		}
	}
}


int main()
{
	Pipe pipe1 = { "No name", 0, 0, 0};
	
	KC kc1 = { "No name", 0, 0, 1.0 };

	int number;

	do {
		print_menu();

		number = input_number(0, 8);

		switch (number) {

		case 1:
			input_pipe_characteristics(pipe1);
			break;

		case 2:
			input_kc_characteristics(kc1);
			break;
			
		case 3:
			view_all_objects(pipe1, kc1);
			break;

		case 4:
			edit_the_pipe(pipe1);
			break;

		case 5:
			edit_the_kc(kc1);
			break;
			
		case 6:
			write_in_file(pipe1, kc1);
			break;

		case 7:
			read_from_file(pipe1, kc1);
			break;

		};


	} while (number != 0);

};
