#pragma once

#include "PartialIndividual.h"

class PartialPopulation
{
public:
	PartialPopulation();
	~PartialPopulation();
	void DeleteNextPartialPopulation();
	void PartialPopulationInit();
	void newGeneration(int cnt);
	void evaluation();
	void evalinit();

	vector<PartialIndividual*> pop;

private:
	void sort(int lb, int ub);
};
