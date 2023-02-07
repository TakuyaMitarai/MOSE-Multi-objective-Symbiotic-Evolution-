#include "PartialPopulation.h"

// �R���X�g���N�^
PartialPopulation::PartialPopulation()
{
}

// �f�X�g���N�^
PartialPopulation::~PartialPopulation()
{
	int i;
	int size = pop.size();
	for(i = 0; i < pop.size(); i++)
		delete pop[i];
}

void PartialPopulation::DeleteNextPartialPopulation()
{
	int i;
	int size = pop.size();
	//cout << size << endl;
	for(i = 0; i < size; i++){
		delete pop[i];
	}
}

void PartialPopulation::PartialPopulationInit()
{
	int i;
	for(i = 0; i < PPOP_SIZE; i++) {
		pop.push_back(new PartialIndividual());
		pop[i]->PartialIndividualInit();
	}
}

// �����㐶��
void PartialPopulation::newGeneration(int cnt)
{
	int i, j, k, a, fit1, tmp1, tmp2, index1, index2;
	int size = cnt;

	/*
	for(k = 0; k < cnt; k++) {
		cout << pop[k]->fitness << endl;
	}
	*/
	
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
			if(fit1 > pop[a]->fitness) {
				fit1 = pop[a]->fitness;
				tmp2 = a;
			}
		}
		index1 = rand() % PCHROM_LEN;
		index2 = ((rand() % (PCHROM_LEN - 1)) + index1) % PCHROM_LEN;

		pop[k]->newGeneration(pop[tmp1], pop[tmp2], index1, index2);
	}
	for(i = 0; i < cnt; i++)
		pop[i]->newGeneration();
}

// �]��
void PartialPopulation::evaluation()
{
	sort(0, PPOP_SIZE - 1);
}

// �]���l������
void PartialPopulation::evalinit()
{
	int i;
	
	for(i = 0; i < pop.size(); i++)
		pop[i]->fitness = 0;
}

// pop��fitness�̒l�ɂ���ď����Ƀ\�[�g�i�N�C�b�N�\�[�g�j
// lb : �\�[�g����pop�͈̔͂̍ŏ��C���f�b�N�X
// rb : �\�[�g����pop�͈̔͂̍ő�C���f�b�N�X
void PartialPopulation::sort(int lb, int ub)
{
	int i, j, k;
	double pivot;
	PartialIndividual* swap;

	if(lb < ub) {
		k = (lb + ub) / 2;
		pivot = pop[k]->fitness;
		i = lb;
		j = ub;
		do {
			while(pop[i]->fitness < pivot)
				i++;
			while(pop[j]->fitness > pivot)
				j--;
			if(i <= j) {
				swap = pop[i];
				pop[i] = pop[j];
				pop[j] = swap;
				i++;
				j--;
			}
		} while(i <= j);
		sort(lb, j);
		sort(i, ub);
	}
}