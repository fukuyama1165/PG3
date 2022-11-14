#include <stdio.h>

int Wages(int time);

int main()
{
	int time = 8;
	int wage = 0;
	for (int i = 0; i < time; i++)
	{
		wage += Wages(i);
	}

	printf("%dŠÔ‚Åˆê”Ê’À‹à‚Í%d‰~AÄ‹N’À‹à‚Í%d‰~", time, 1072 * time, wage);

	return 0;
}

int Wages(int time)
{
	if (time == 0)
	{
		return 100;
	}
	else
	{
		return Wages(time - 1) * 2 - 50;
	}

}
