#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

typedef void (*PFunc)(int a, int b);

void SetTimeout(PFunc func, int second, int ans, int select)
{

	Sleep(second);

	func(select, ans);

}

void ComparisonNum(int select, int randNum)
{


	printf("%d\n", randNum);
	if (randNum % 2 == 0 and select == 0)
	{
		printf("正解\n");
	}
	else if (randNum % 2 == 1 and select == 1)
	{
		printf("正解\n");
	}
	else
	{
		printf("不正解\n");
	}

}



int main()
{
	//入力
	int select;
	printf("入力:偶数->0 奇数->1\n");
	scanf_s("%d", &select);

	//答えの決定
	int ans = 0;
	srand(time(nullptr));

	ans = rand() % 100;

	//関数をセット
	PFunc func;
	func = ComparisonNum;

	//実行
	SetTimeout(func, 3000, ans, select);

	return 0;
}