#include "SymbioticEvolution.h"

// コンストラクタ
SymbioticEvolution::SymbioticEvolution()
{
	int i, j;

	// 部分解初期化
	ppop[0] = new PartialPopulation();
	ppop[0]->PartialPopulationInit();
	// 次世代部分解初期化
	ppop[1] = new PartialPopulation();
	ppop[2] = new PartialPopulation();
	WholeIndividual::ppop = ppop;

	// 全体解初期化
	wpop = new WholePopulation();

	//パレートランキングと混雑距離による評価
	wpop->evaluation();
}

// デストラクタ
SymbioticEvolution::~SymbioticEvolution()
{
	int i;
	for(i = 0; i < 3; i++) {
		delete ppop[i];
	}
	delete wpop;
}

// 探索
void SymbioticEvolution::solve(void)
{
	int gen, i, j, cnt;
	vector<double> x, y;
	matplotlib g;

	for(gen = 1; gen <=	GENERATION_MAX; gen++) {
		cout << "第" << gen << "世代" << endl;

		//部分解Qt+1
		cnt = wpop->newPartialGeneration();

		//部分解Rt+1
		ppop[0]->newGeneration(cnt);

		//全体解Rt+1
		wpop->newWholeGeneration();

		// 部分解適応度初期化
		ppop[0]->evalinit();

		//パレートランキングと混雑距離による評価
		wpop->evaluation();
	}
	wpop->printfitness();
	//wpop->printsolution();
}
