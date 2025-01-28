#pragma once

#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "process.h"


enum Strategy { INFINITE, FIRST_FIT, PAGED, VIRTUAL };

class Allocator {
private:
	unsigned int quantum;
	Strategy strategy;
	int simulation;

public:
	Allocator(unsigned int _quantum, Strategy _strategy) : quantum(_quantum), strategy(_strategy), simulation(0) {}
};


#endif