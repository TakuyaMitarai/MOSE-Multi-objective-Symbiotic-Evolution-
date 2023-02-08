#include "PartialPopulation.h"

// コンストラクタ
PartialPopulation::PartialPopulation()
{
}

// デストラクタ
PartialPopulation::~PartialPopulation()
{
	int i;
	int size = pop.size();
	for(i = 0; i < pop.size(); i++)
		delete pop[i];
}

//部分解初期化
void PartialPopulation::PartialPopulationInit()
{
	int i;
	for(i = 0; i < PPOP_SIZE; i++) {
		pop.push_back(new PartialIndividual());
		pop[i]->PartialIndividualInit();
	}
}

// 混雑度トーナメントによるQp(t+1)生成
void PartialPopulation::newGeneration(int cnt)
{
	int i, j, k, a, fit1, tmp1, tmp2, index1, index2;
	int size = cnt;

	for(k = cnt; k < cnt * 2; k++) {
		tmp1 = rand() % size + cnt;
		fit1 = pop[tmp1]->fitness;
		for(i = 0; i < TOURNAMENT_SIZE; i++) {
			a = rand() % size + cnt;
			if(fit1 < pop[a]->fitness) {
				fit1 = pop[a]->fitness;
				tmp1 = a;
			}
		}
		tmp2 = rand() % size + cnt;
		fit1 = pop[tmp2]->fitness;
		for(i = 0; i < TOURNAMENT_SIZE; i++) {
			a = rand() % size + cnt;
			if(fit1 < pop[a]->fitness) {
				fit1 = pop[a]->fitness;
				tmp2 = a;
			}
		}
		index1 = rand() % PCHROM_LEN;
		index2 = ((rand() % (PCHROM_LEN - 1)) + index1) % PCHROM_LEN;

		pop[k]->newGeneration(pop[tmp1], pop[tmp2], index1, index2);
	}
	for(i = cnt; i < cnt * 2; i++)
		pop[i]->newGeneration();
}

// 適応度初期化
void PartialPopulation::evalinit()
{
	int i;
	
	for(i = 0; i < pop.size(); i++)
		pop[i]->fitness = 0;
}