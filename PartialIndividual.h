#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

// �萔�̒�`
#define GENERATION_MAX	400			// �����㐔
#define WPOP_SIZE		800					// �S�̉��W�c���̌̂̐�
#define PPOP_SIZE		600						// �������W�c���̌̂̐�
#define MUTATE_PROB		0.02					// �ˑR�ψيm��
#define MUTATE_PROB2	0.001					// �ˑR�ψيm��
#define MUTATE_PROBI	MUTATE_PROB*RAND_MAX	// �ˑR�ψيm���~�����̍ő�l
#define MUTATE_PROBI2	MUTATE_PROB2*RAND_MAX	// �ˑR�ψيm���~�����̍ő�l
#define MAX_NUM			WCHROM_LEN*PCHROM_LEN	// �t���C�h���ɂ�����N
#define WCHROM_LEN		2						// �S�̉��̐��F�̂̒���
#define PCHROM_LEN		5						// �������̐��F�̂̒���
#define TOURNAMENT_SIZE 10
#define PI				3.141592

class PartialIndividual
{
public:
	PartialIndividual();
	~PartialIndividual();
	void PartialIndividualInit();
	void newGeneration();
	void newGeneration(PartialIndividual* p);
	void newGeneration(PartialIndividual* p1, PartialIndividual* p2, int index1, int index2);

	double chrom[PCHROM_LEN];	// ���F��
	double fitness;			// �K���x

private:
	void mutate();
};
