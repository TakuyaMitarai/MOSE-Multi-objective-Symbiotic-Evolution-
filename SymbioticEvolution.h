#pragma once

#include "WholePopulation.h"

class SymbioticEvolution
{
public:
	SymbioticEvolution();
	~SymbioticEvolution();
	void solve();

	WholePopulation* wpop;
	PartialPopulation* ppop[3];
};
