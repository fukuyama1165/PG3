#include "SceneManager.h"

SceneManager::SceneManager()
{

}
SceneManager::~SceneManager()
{

}

SceneManager* SceneManager::GetInstance()
{

	static SceneManager instance;

	return &instance;

}

void SceneManager::ChangeScene(int sceneNo)
{


	if (sceneNo == 0)
	{
		printf("TitleScene\n");
	}

	if (sceneNo == 1)
	{
		printf("NewGameScene\n");
	}

	if (sceneNo == 2)
	{
		printf("GamePlayScene\n");
	}

	if (sceneNo == 3)
	{
		printf("GameClearScene\n");
	}

}