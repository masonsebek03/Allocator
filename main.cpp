#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include "Allocator.h"
#include <sstream>
#include <queue>
#include <fstream>

int main(int argc, char** argv)
{
	std::vector<std::string> args(argv + 1, argv + argc);
	std::unordered_map<std::string, std::string> arguments;
	std::queue<process_t*> process_list; // process queue in allocator, process_list in main or delegated


	std::map<std::string, Strategy> stringToStrategy = {
		{"infinite", Strategy::INFINITE},
		{"paged", Strategy::PAGED},
		{"virtual", Strategy::VIRTUAL},
		{"first-fit", Strategy::FIRST_FIT},
	};

	for (int i = 0; i < args.size(); i++) {
		if (args[i][0] != '-') {
			arguments[args[i - 1]] = args[i];
		}
	}

	std::string fileName = arguments["-f"];
	std::string memory = arguments["-m"];
	unsigned int quantum = stoi(arguments["-q"]);


	// read in data from file (delegate to another class)
	std::ifstream file(fileName);
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string line;
	while (std::getline(buffer, line)) {
		process_t* process;
		sscanf(line.c_str(), "%d %s %d %d", &process->arrivalTime, process->name, &process->runTime, &process->memorySize);
		process_list.push(process);
	}


	Allocator allocator(quantum, stringToStrategy[memory]);



	return 0;


}