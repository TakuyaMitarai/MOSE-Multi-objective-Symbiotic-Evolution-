#include "WholeIndividual.h"
#include <math.h>

PartialPopulation** WholeIndividual::ppop = NULL;

// �R���X�g���N�^
WholeIndividual::WholeIndividual()
{
	int i;

	for(i = 0; i < WCHROM_LEN; i++)
		chrom[i] = ppop[0]->pop[rand() % PPOP_SIZE];
	fitness = 0;
	rankfit = DBL_MAX;
}

// �f�X�g���N�^
WholeIndividual::~WholeIndividual()
{

}

// �����㐶���i�����_���j
void WholeIndividual::newGeneration()
{
	int i;

	for(i = 0; i < WCHROM_LEN; i++)
		chrom[i] = ppop[0]->pop[rand() % PPOP_SIZE];
	fitness = 0;
	rankfit = DBL_MAX;
}

// �����㐶���i�R�s�[���ˑR�ψفj
// p: �R�s�[���̂ւ̃|�C���^
void WholeIndividual::newGeneration(WholeIndividual* p)
{
	int i;
	
	for(i = 0; i < WCHROM_LEN; i++)
		chrom[i] = p->chrom[i];
	mutate();
	fitness = 0;
	rankfit = DBL_MAX;
}

// �����㐶���i�Q�_�������ˑR�ψفj
// p1: �e�̂��̂P
// p2: �e�̂��̂Q
// index1: �����_�i0�`WCHROM_LEN-1�j
// index2: �����_�i0�`WCHROM_LEN-1�j
void WholeIndividual::newGeneration(WholeIndividual* p1, WholeIndividual* p2, int index1, int index2)
{
	int i, min, max;

	if(index1 < index2) {
		min = index1;
		max = index2;
	} else {
		min = index2;
		max = index1;
	}
	for(i = 0; i < min; i++)
		chrom[i] = p1->chrom[i];
	for( ; i < max; i++)
		chrom[i] = p2->chrom[i];
	for( ; i < PCHROM_LEN; i++)
		chrom[i] = p1->chrom[i];
	mutate();
	fitness = 0;
	rankfit = DBL_MAX;
}

// �ˑR�ψ�
void WholeIndividual::mutate()
{
	int i;
	int length = ppop[0]->pop.size();
	for(i = 0; i < WCHROM_LEN; i++) {
		if(rand() < MUTATE_PROBI2)
			chrom[i] = ppop[0]->pop[rand() % length];
	}
}

// �]��
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

	//ZDT4
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

	//cout << fitness1 << " " << fitness2 << endl;
}