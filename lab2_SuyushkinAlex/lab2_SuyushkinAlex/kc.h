#pragma once

#include <string>

class KC
{
private:

	int id;
	static int MaxID;
	std::string name;
	int number_of_workshops;
	int number_of_operating_workshops;
	float effectiveness;

public:

	KC();

	static int get_MaxID();
	int get_id() const;
	std::string get_name() const;
	int get_number_of_workshops() const;
	int get_number_of_operating_workshops() const;
	float get_effectiveness() const;


	void set_number_of_operating_workshops(int new_number_of_operating_workshops);


	friend std::ostream& operator << (std::ostream& out, const KC& pipe);
	friend std::istream& operator >> (std::istream& in, KC& pipe);
};

