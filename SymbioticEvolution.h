#pragma once

#include "WholePopulation.h"
#include "matplotlib.h"

class SymbioticEvolution
{
public:
	SymbioticEvolution();
	~SymbioticEvolution();
	void solve();

	WholePopulation* wpop;
	PartialPopulation* ppop[4];
};
