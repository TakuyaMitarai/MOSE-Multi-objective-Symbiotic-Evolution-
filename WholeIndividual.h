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

	PartialIndividual* chrom[WCHROM_LEN];	// 染色体
	long double fitness1;					// 目的関数の適応度１
	long double fitness2;					// 目的関数の適応度２
	double fitness;							// 混雑度とパレートランキング
	double rankfit;							// パレートランキング
};
