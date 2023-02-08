#pragma once

#include "PartialIndividual.h"

class PartialPopulation
{
public:
	PartialPopulation();
	~PartialPopulation();
	void PartialPopulationInit();
	void newGeneration(int cnt);
	void evalinit();

	vector<PartialIndividual*> pop;
};
