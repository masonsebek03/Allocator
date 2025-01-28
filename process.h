#pragma once

#ifndef PROCESS_H
#define PROCESS_H

#include <string>

/*
Properties of a process:
- State (running, ready, blocked) (ENUM)
- Run time (int)
- Process name (std::string)
- Memory Requirement (int)
- Arrival time (int)
*/


enum ProcessState { READY, RUNNING, BLOCKED };

struct process_t {
	int runTime;
	int arrivalTime;
	std::string name;
	unsigned int memorySize;
	ProcessState state;

	process_t(int _runTime, int _arrivalTime, std::string _name, 
			  unsigned int _memorySize, ProcessState _state) : 
		      runTime(_runTime), arrivalTime(_arrivalTime), 
			  name(_name), memorySize(_memorySize), state(_state) {}

	process_t(int _runTime, int _arrivalTime, std::string _name, ProcessState _state) :
		runTime(_runTime), arrivalTime(_arrivalTime),
		name(_name), state(_state) {}

};

process_t& getProcess(std::string line, process_t* process) {
	sscanf(line.c_str(), "%d %s %d %d", &process->arrivalTime, process->name, &process->runTime, &process->memorySize);
}



#endif