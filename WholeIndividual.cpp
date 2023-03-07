#include "WholeIndividual.h"
#include <math.h>

PartialPopulation** WholeIndividual::ppop = NULL;

// コンストラクタ
WholeIndividual::WholeIndividual()
{
	int i;

	for(i = 0; i < WCHROM_LEN; i++)
		chrom[i] = ppop[0]->pop[rand() % PPOP_SIZE];
	fitness = 0;
	rankfit = DBL_MAX;
}

// デストラクタ
WholeIndividual::~WholeIndividual()
{

}

// 全体解突然変異
void WholeIndividual::mutate()
{
	int i;
	int length = ppop[0]->pop.size();
	for(i = 0; i < WCHROM_LEN; i++) {
		if(rand() < MUTATE_PROBI2)
			chrom[i] = ppop[0]->pop[rand() % length];
	}
}

// 目的関数
void WholeIndividual::objective_evaluation()
{
	int i, j;
	long double gx = 0;
	long double hx = 0;
	long double sum1 = 0;
	long double sum2 = 0;

	fitness = 0.0;
	fitness1 = 0.0;
	fitness2 = 0.0;
	rankfit = 0.0;
	
	/*
	//MOP
	fitness1 = (chrom[0]->chrom[0] + 30) / 60;
	for(i = 0; i < WCHROM_LEN; i++) {
		for(j = 0; j < PCHROM_LEN; j++){
			if(i != 0 || j != 0) {
				gx += chrom[i]->chrom[j] * chrom[i]->chrom[j] - 10 * cos(2 * PI * chrom[i]->chrom[j]);
			}
		}
	}
	gx = 1 + 10 * (PCHROM_LEN * WCHROM_LEN - 1) + gx;
	if(fitness1 <=gx) {
		hx = 1 - pow(fitness1/gx, 0.5);
	} else {
		hx = 0;
	}

	fitness2 = gx * hx;
	*/

	//Fonseca-fleming function
	/*
	fitness1 = chrom[0]->chrom[0];
	for(i = 0; i < WCHROM_LEN; i++) {
		for(j = 0; j < PCHROM_LEN; j++){
			if(i != 0 || j != 0) {
				gx += chrom[i]->chrom[j];
			}
		}
	}
	gx = 1 + 9 / 29 * gx;
	hx = 1 - sqrt(fitness1 / gx);
	fitness2 = gx * hx;
	*/

	/*
	for(i = 0; i < WCHROM_LEN; i++) {
		for(j = 0; j < PCHROM_LEN; j++){
			sum1 += pow((chrom[i]->chrom[j] -  1 / sqrt(i*PCHROM_LEN+j+1)),2);
			sum2 += pow((chrom[i]->chrom[j] +  1 / sqrt(i*PCHROM_LEN+j+1)),2);
		}
	}
	fitness1 = 1 - pow(2.71828, -sum1);
	fitness2 = 1 - pow(2.71828, -sum2);
	*/
	/*
	//ZDT3
	fitness1 = chrom[0]->chrom[0];
	for(i = 0; i < WCHROM_LEN; i++) {
		for(j = 0; j < PCHROM_LEN; j++){
			if(i != 0 || j != 0) {
				gx += chrom[i]->chrom[j];
			}
		}
	}
	gx = 1 + 9 * gx / (WCHROM_LEN * PCHROM_LEN - 1);
	hx = 1 - pow(fitness1 / gx, 0.5) - fitness1 / gx * sin(10 * PI * fitness1);
	fitness2 = gx * hx;
	*/

	//ZDT4
	/*
	fitness1 = (chrom[0]->chrom[0] + 5) / 10;
	for(i = 0; i < WCHROM_LEN; i++) {
		for(j = 0; j < PCHROM_LEN; j++){
			if(i != 0 || j != 0) {
				gx += chrom[i]->chrom[j] * chrom[i]->chrom[j] - 10 * cos(4 * PI * chrom[i]->chrom[j]);
			}
		}
	}
	gx = 91 + gx;
	hx = 1 - pow(fitness1/gx, 0.5);

	fitness2 = gx * hx;
	*/

	/*
	//Discontinuous Pareto-optimal front
	fitness1 = chrom[0]->chrom[0];
	for(i = 0; i < WCHROM_LEN; i++) {
		for(j = 0; j < PCHROM_LEN; j++){
			if(i != 0 || j != 0) {
				gx += chrom[i]->chrom[j];
			}
		}
	}
	gx = 1 + 10 * gx / (WCHROM_LEN * PCHROM_LEN - 1);
	hx = 1 - pow(fitness1 / gx, 0.25) - fitness1 / gx * sin(10 * PI * fitness1);
	fitness2 = gx * hx;
	*/

	
	//KUR
	fitness1 = 0;
	for(i = 0; i < WCHROM_LEN; i++) {
		for(j = 0; j < PCHROM_LEN; j++){
			if(i != WCHROM_LEN - 1 || j != PCHROM_LEN - 1) {
				if(j == PCHROM_LEN - 1) {
					fitness1 += -10 * pow(2.71828, -0.2 * sqrt(chrom[i]->chrom[j] * chrom[i]->chrom[j] + chrom[i+1]->chrom[0] * chrom[i+1]->chrom[0]));
				} else{
					fitness1 += -10 * pow(2.71828, -0.2 * sqrt(chrom[i]->chrom[j] * chrom[i]->chrom[j] + chrom[i]->chrom[j + 1] * chrom[i]->chrom[j + 1]));
				}
			}
		}
	}
	fitness2 = 0;
	for(i = 0; i < WCHROM_LEN; i++) {
		for(j = 0; j < PCHROM_LEN; j++){
			fitness2 += pow(abs(chrom[i]->chrom[j]), 0.8) + 5 * sin(chrom[i]->chrom[j] * chrom[i]->chrom[j] * chrom[i]->chrom[j]);
		}
	}
	//cout << fitness1 << " " << fitness2 << endl;
}