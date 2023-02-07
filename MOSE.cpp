// floydSE.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "SymbioticEvolution.h"

// メインルーチン
int main()
{
	int i;
	float comptime;
	clock_t start;
	SymbioticEvolution *se;

	// 時間計測スタート
	start = clock();

	// 乱数のタネの設定
	srand((unsigned int)time(NULL));

	// 解探索
	se = new SymbioticEvolution();
	se->solve();

	// 処理時間計算
	comptime = (float)(clock() - start) / CLOCKS_PER_SEC;

	// 結果表示
	/*
	printf("集合A：");
	for(i = 0; i < MAX_NUM; i++) {
		if(se->best[i] == 1)
			printf("%d ", i+1);
	}
	printf("\n集合B：");
	for(i = 0; i < MAX_NUM; i++) {
		if(se->best[i] == 0)
			printf("%d ", i+1);
	}
	printf("\n最良個体の適応度：%f\n", se->bestfit);
	*/
	printf("処理時間：%f秒\n", comptime);

	// 後処理
	//delete se;

	return 0;
}
