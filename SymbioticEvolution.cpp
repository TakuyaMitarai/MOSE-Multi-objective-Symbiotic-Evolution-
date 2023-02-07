#include "SymbioticEvolution.h"

// �R���X�g���N�^
SymbioticEvolution::SymbioticEvolution()
{
	int i, j;

	// �����W�c����
	ppop[0] = new PartialPopulation();
	ppop[0]->PartialPopulationInit();
	//next_gen
	ppop[1] = new PartialPopulation();
	ppop[2] = new PartialPopulation();
	WholeIndividual::ppop = ppop;
	wpop = new WholePopulation();
	//wpop->printsolution();
	wpop->evaluation();
	cout << "初期化完了" << endl;
	//wpop->printsolution();
}

// �f�X�g���N�^
SymbioticEvolution::~SymbioticEvolution()
{
	int i;
	delete ppop[0];
	delete ppop[1];
	delete wpop;
}

// �i��
void SymbioticEvolution::solve(void)
{
	int gen, i, j, cnt;

	for(gen = 1; gen <=	GENERATION_MAX; gen++) {
		cout << "第" << gen << "世代" << endl;

		//wpop->printsolution();
		//cout << " checkpointNewPaP" << endl;
		//部分解Pt+1
		cnt = wpop->newPartialGeneration();
		//cout << "部分解Pt" << endl;
		//cout << cnt << endl;

		//部分解Qt+1
		ppop[0]->newGeneration(cnt);
		//cout << "部分解Qt" << endl;

		//全体解Qt+1
		wpop->newWholeGeneration(cnt);
		//cout << "全体解Qt" << endl;

		// 初期化
		ppop[0]->evalinit();
		//cout << "評価1" << endl;
		wpop->evaluation();
		//cout << "評価" << endl;
		//wpop->printfitness();

		//wpop->printsolution();

		//cout << "第" << gen << "世代完了" << endl;
		/*
		if(wpop->pop[0]->fitness < bestfit) {
			bestfit = wpop->pop[0]->fitness;
			for(i = 0; i < WCHROM_LEN; i++) {
				for(j = 0; j < PCHROM_LEN; j++)
					best[i*PCHROM_LEN+j] = wpop->pop[0]->chrom[i]->chrom[j];
			}
			printf("��%d����\t�ŗǌ̂̓K���x��%f\n", gen, bestfit);
		}
		*/
	}
	wpop->printfitness();
}
