#pragma once

#include "WholeIndividual.h"

class WholePopulation
{
public:
	WholePopulation();
	~WholePopulation();
	int newPartialGeneration();
	void newWholeGeneration(int cnt);
	void evaluation();
	void congestion(int rank,vector<int> rank_s);
	void printsolution();
	void printfitness();

	WholeIndividual* pop[WPOP_SIZE*2];	// �̏W�c

private:
	void sort(int lb, int ub);
	void sortobject(int lb, int ub, vector<int> rank_s);
	void sortobject2(int lb, int ub, vector<int> rank_s);
};