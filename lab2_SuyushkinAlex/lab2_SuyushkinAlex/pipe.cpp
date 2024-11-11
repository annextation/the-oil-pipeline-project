#include <iostream>
#include <string>

#include "pipe.h"
#include "utils.h"


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
	out << "pipe name: " << pipe.name << endl <<
		"pipe diameter: " << pipe.diameter << endl <<
		"pipe lenght: " << pipe.lenght << endl <<
		"pipe repair: " << pipe.repair << endl << endl;

	return out;
}

istream& operator >> (istream& in, Pipe& pipe)
{
	cout << "pipe name > ";
	cin.ignore();
	getline(in, pipe.name);
	cout << "pipe lenght > ";
	pipe.lenght = GetCorrectNumber<double>(1, 999);
	cout << "pipe diameter > ";
	pipe.diameter = GetCorrectNumber<int>(1, 199);
	cout << "pipe repair > ";
	pipe.repair = GetCorrectNumber<bool>(0, 1);

	return in;
}