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
		printf("����\n");
	}
	else if (randNum % 2 == 1 and select == 1)
	{
		printf("����\n");
	}
	else
	{
		printf("�s����\n");
	}

}



int main()
{
	//����
	int select;
	printf("����:����->0 �->1\n");
	scanf_s("%d", &select);

	//�����̌���
	int ans = 0;
	srand(time(nullptr));

	ans = rand() % 100;

	//�֐����Z�b�g
	PFunc func;
	func = ComparisonNum;

	//���s
	SetTimeout(func, 3000, ans, select);

	return 0;
}