#pragma once

#include "PartialPopulation.h"

class WholeIndividual
{
public:
	static PartialPopulation** ppop;

	WholeIndividual();
	~WholeIndividual();
	void objective_evaluation();
	void mutate();

	PartialIndividual* chrom[WCHROM_LEN];	// ���F��
	long double fitness1;							// �K���x
	long double fitness2;
	double fitness;
	double rankfit;
};
