#pragma once

#include <string>
#include <unordered_map>

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
	KC(std::ifstream& file);

	static int get_MaxID();
	int get_id() const;
	std::string get_name() const;
	int get_number_of_workshops() const;
	int get_number_of_operating_workshops() const;
	float get_effectiveness() const;

	static void set_max_id(const std::unordered_map<int, KC>& kc);
	void set_number_of_operating_workshops(int new_number_of_operating_workshops);


	friend std::ostream& operator << (std::ostream& out, const KC& kc);
	friend std::istream& operator >> (std::istream& in, KC& kc);

	void save(std::ofstream& kc) const;
	
};

