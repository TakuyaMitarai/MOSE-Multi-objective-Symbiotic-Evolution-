#pragma once

#include "PartialPopulation.h"

class WholeIndividual
{
public:
	static PartialPopulation** ppop;

	WholeIndividual();
	~WholeIndividual();
	void newGeneration();
	void newGeneration(WholeIndividual* p);
	void newGeneration(WholeIndividual* p1, WholeIndividual* p2, int index1, int index2);
	void objective_evaluation();
	void mutate();

	PartialIndividual* chrom[WCHROM_LEN];	// ���F��
	long double fitness1;							// �K���x
	long double fitness2;
	double fitness;
	double rankfit;

private:
};
