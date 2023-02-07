#include "PartialIndividual.h"

// �R���X�g���N�^
PartialIndividual::PartialIndividual()
{
}

// �f�X�g���N�^
PartialIndividual::~PartialIndividual()
{

}

void PartialIndividual::PartialIndividualInit()
{
	int i;
	
	for(i = 0; i < PCHROM_LEN; i++) {
		//chrom[i] =  (double)(rand() % 60000) / 1000 - 30;
		//chrom[i] =  (double)(rand() % 80000) / 10000 - 4;
		chrom[i] =  (double)(rand() % 10000) / 1000 - 5; //ZDT4
	}
	fitness = 0;
}

// �����㐶���i�ˑR�ψق̂݁j
void PartialIndividual::newGeneration()
{
	mutate();
	fitness = 0;
}

// �����㐶���i�R�s�[���ˑR�ψفj
// p: �R�s�[���̂ւ̃|�C���^
void PartialIndividual::newGeneration(PartialIndividual* p)
{
	int i;
	
	for(i = 0; i < PCHROM_LEN; i++)
		chrom[i] = p->chrom[i];
	mutate();
	fitness = 0;
}

// �����㐶���i�Q�_�������ˑR�ψفj
// p1: �e�̂��̂P
// p2: �e�̂��̂Q
// index1: �����_�i0�`PCHROM_LEN-1�j
// index2: �����_�i0�`PCHROM_LEN-1�j
void PartialIndividual::newGeneration(PartialIndividual* p1, PartialIndividual* p2, int index1, int index2)
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
}

// �ˑR�ψ�
void PartialIndividual::mutate()
{
	int i;

	for(i = 0; i < PCHROM_LEN; i++) {
		if(rand() < MUTATE_PROBI){
			chrom[i] =  (double)(rand() % 10000) / 1000 - 5; //ZDT4
			//chrom[i] =  (double)(rand() % 60000) / 1000 - 30;
			//chrom[i] =  (double)(rand() % 80000) / 10000 - 4;
		}
	}
}
