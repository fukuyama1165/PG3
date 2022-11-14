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

	//“ü—Í
	int select;
	printf("“ü—Í:‹ô”->0 Šï”->1\n");
	scanf_s("%d", &select);

	//“š‚¦‚ÌŒˆ’è
	int ans = 0;
	srand(time(nullptr));

	ans = rand() % 100;

	//ŠÖ”‚Ìì¬
	std::function<void()> judgeFunc = [&]()
	{

		printf("%d\n", ans);
		if (ans % 2 == 0 and select == 0)
		{
			printf("³‰ğ\n");
		}
		else if (ans % 2 == 1 and select == 1)
		{
			printf("³‰ğ\n");
		}
		else
		{
			printf("•s³‰ğ\n");
		}

	};

	//Às
	SetTimeout(judgeFunc, 2700);

	return 0;

}