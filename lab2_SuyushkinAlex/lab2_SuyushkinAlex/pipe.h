#pragma once

#include <string>
#include <unordered_map>

class Pipe 
{
	private:

		int id;
		static int MaxID;
		std::string name;
		double lenght;
		int diameter;
		bool repair;

	public:

		Pipe();
		Pipe(std::ifstream& file);

		static int get_MaxID();
		int get_id() const;
		std::string get_name() const;
		double get_lenght() const;
		int get_diameter() const;
		bool get_repair() const;

		void set_repair(bool new_repair);

		static void set_max_id(const std::unordered_map<int, Pipe>& pipe);

		friend std::ostream& operator << (std::ostream& out, const Pipe& pipe);
		friend std::istream& operator >> (std::istream& in, Pipe& pipe);

		void save(std::ofstream& file) const;	
};

