#include "SymbioticEvolution.h"

// コンストラクタ
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

// デストラクタ
SymbioticEvolution::~SymbioticEvolution()
{
	int i;
	delete ppop[0];
	delete ppop[1];
	delete wpop;
}

// 探索
void SymbioticEvolution::solve(void)
{
	int gen, i, j, cnt;

	for(gen = 1; gen <=	GENERATION_MAX; gen++) {
		cout << "第" << gen << "世代" << endl;

		//部分解Pt+1
		cnt = wpop->newPartialGeneration();

		//部分解Qt+1
		ppop[0]->newGeneration(cnt);

		//全体解Qt+1
		wpop->newWholeGeneration();

		// 部分解適応度初期化
		ppop[0]->evalinit();

		//パレートランキングによる評価
		wpop->evaluation();
		
		//wpop->printfitness();
		//wpop->printsolution();
	}
	wpop->printfitness();
}
