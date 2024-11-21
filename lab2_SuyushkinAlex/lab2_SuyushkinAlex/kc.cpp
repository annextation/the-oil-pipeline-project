#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "kc.h"
#include "utils.h"


using namespace std;

int KC::MaxID = 0;

int KC::get_MaxID() {
	return KC::MaxID;
}

int KC::get_id() const {
	return this->id;
}

string KC::get_name() const {
	return this->name;
}

int KC::get_number_of_workshops() const {
	return this->number_of_workshops;
}

int KC::get_number_of_operating_workshops() const {
	return this->number_of_operating_workshops;
}

float KC::get_effectiveness() const {
	return this->effectiveness;
}

void KC::set_number_of_operating_workshops(int new_number_of_operating_workshops) {
	this->number_of_operating_workshops = new_number_of_operating_workshops;
}

KC::KC() {
	id = ++MaxID;
	name = "No Name";
	number_of_workshops = 0;
	number_of_operating_workshops = 0;
	effectiveness = 0.0;
}

ostream& operator << (ostream& out, const KC& kc)
{
	out <<
		"ID: " << kc.id << endl << 
		"kc name: " << kc.name << endl <<
		"kc number_of_workshops: " << kc.number_of_workshops << endl <<
		"kc number_of_operating_workshops: " << kc.number_of_operating_workshops << endl <<
		"kc effectiveness: " << kc.effectiveness << endl << endl;

	return out;
}

istream& operator >> (istream& in, KC& kc)
{
	cout << "kc name > ";
	cin.ignore();
	getline(in, kc.name);
	cout << "kc number_of_workshops > ";
	kc.number_of_workshops = GetCorrectNumber<int>(1, 100);
	cout << "kc number_of_operating_workshops > ";
	kc.number_of_operating_workshops = GetCorrectNumber<int>(0, kc.number_of_workshops);
	cout << "kc effectiveness > ";
	kc.effectiveness = GetCorrectNumber<float>(0.1, 100.0);

	return in;
}

void KC::save(ofstream& file) const {
	file << "KC" << endl;
	file << this->id << endl;
	file << this->name << endl;
	file << this->number_of_workshops << endl;
	file << this->number_of_operating_workshops << endl;
	file << this->effectiveness << endl;
}

void KC::set_max_id(const unordered_map<int, KC>& kc) {
	KC::MaxID = get_max_id(kc);
}

KC::KC(std::ifstream& file) {
	file >> this->id;
	file.ignore(10000, '\n');
	getline(file >> std::ws, this->name);
	file >> this->number_of_workshops;
	file >> this->number_of_operating_workshops;
	file >> this->effectiveness;
}