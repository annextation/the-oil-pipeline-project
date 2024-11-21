#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "pipe.h"
#include "utils.h"
#include <unordered_map>


using namespace std;

int Pipe::MaxID = 0;

int Pipe::get_MaxID() {
	return Pipe::MaxID;
}

int Pipe::get_id() const {
	return this->id;
}

string Pipe::get_name() const {
	return this->name;
}

double Pipe::get_lenght() const {
	return this->lenght;
}

int Pipe::get_diameter() const {
	return this->diameter;
}

bool Pipe::get_repair() const {
	return this->repair;
}

void Pipe::set_repair(bool new_repair) {
	this->repair = new_repair;
}

Pipe::Pipe() {
	id = ++MaxID;
	name = "No Name";
	diameter = 0;
	lenght = 0;
	repair = false;
}

ostream& operator << (ostream& out, const Pipe& pipe)
{
	out << "ID " << pipe.id << endl <<
		"pipe name: " << pipe.name << endl <<
		"pipe diameter: " << pipe.diameter << endl <<
		"pipe lenght: " << pipe.lenght << endl <<
		"pipe repair: " << pipe.repair << endl << endl;

	return out;
}

istream& operator >> (istream& in, Pipe& pipe)
{
	cout << "pipe name > ";
	INPUT_LINE(in, pipe.name);
	cout << "pipe lenght > ";
	pipe.lenght = GetCorrectNumber<double>(1, 999);
	cout << "pipe diameter > ";
	pipe.diameter = GetCorrectNumber<int>(1, 199);
	cout << "pipe repair > ";
	pipe.repair = GetCorrectNumber<bool>(0, 1);

	return in;
}

void Pipe::save(ofstream& file) const {
	file << "Pipe" << endl;
	file << this->id << endl;
	file << this->name << endl;
	file << this->lenght << endl;
	file << this->diameter << endl;
	file << this->repair << endl;
}

void Pipe::set_max_id(const unordered_map<int, Pipe>& pipe) {
	Pipe::MaxID = get_max_id(pipe);
}

Pipe::Pipe(std::ifstream& file) {
	file >> this->id;
	file.ignore(10000, '\n');
	getline(file >> std::ws, this->name);
	file >> this->lenght;
	file >> this->diameter;
	file >> this->repair;
}