#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "pipe.h"


void add_pipe(std::unordered_map<int, Pipe>& list_of_pipes);

void veiw_all_pipes(std::unordered_map<int, Pipe>& list_of_pipes);

void delete_pipe(std::unordered_map<int, Pipe>& list_of_pipes);

void edit_pipe_repair(std::unordered_map<int, Pipe>& list_of_pipes);