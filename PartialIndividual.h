#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

// 定数
#define GENERATION_MAX	1000					// 世代交代数
#define WPOP_SIZE		1000					// 全体解個体数
#define PPOP_SIZE		5000					// 部分個体数
#define MUTATE_PROB		0.01					// 部分解突然変異確率
#define MUTATE_PROB2	0.001					// 全体解突然変異確率
#define MUTATE_PROBI	MUTATE_PROB*RAND_MAX	// 部分解突然変異 * RAND_MAX
#define MUTATE_PROBI2	MUTATE_PROB2*RAND_MAX	// 全体解突然変異 * RAND_MAX
#define WCHROM_LEN		5						// 全体解遺伝子数
#define PCHROM_LEN		20						// 部分解遺伝子数
#define TOURNAMENT_SIZE 50						// 混雑度トーナメント数
#define PI				3.141592

class PartialIndividual
{
public:
	PartialIndividual();
	~PartialIndividual();
	void PartialIndividualInit();
	void newGeneration();
	void newGeneration(PartialIndividual* p1, PartialIndividual* p2, int index1, int index2);

	double chrom[PCHROM_LEN];	// ���F��
	double fitness;			// �K���x

private:
	void mutate();
};
