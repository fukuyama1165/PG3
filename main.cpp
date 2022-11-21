#include <stdio.h>
#include <iostream>
#include <list>
#include "SceneManager.h"



int main()
{
	
	int scene = 0;
	int change = 0;

	while (1)
	{
		printf("Change:1\nEnd:0\n");
		SceneManager::GetInstance()->ChangeScene(scene);
		scanf_s("%d", &change);

		if (change == 1)
		{
			if (scene == 3)
			{
				scene = 0;
			}
			else
			{
				scene++;
			}
			
		}
		else if (change == 0)
		{
			break;
		}

		
		
		

		change = '\n';
		
	}

	system("pause");
	return 0;
}