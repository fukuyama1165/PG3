#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

void SetTimeout(std::function<void()> func, int second)
{

	Sleep(second);

	func();

}

int main(int argc, const char* argv[])
{

	//����
	int select;
	printf("����:����->0 �->1\n");
	scanf_s("%d", &select);

	//�����̌���
	int ans = 0;
	srand(time(nullptr));

	ans = rand() % 100;

	//�֐��̍쐬
	std::function<void()> judgeFunc = [&]()
	{

		printf("%d\n", ans);
		if (ans % 2 == 0 and select == 0)
		{
			printf("����\n");
		}
		else if (ans % 2 == 1 and select == 1)
		{
			printf("����\n");
		}
		else
		{
			printf("�s����\n");
		}

	};

	//���s
	SetTimeout(judgeFunc, 2700);

	return 0;

}