#pragma once
#include <stdio.h>
class SceneManager final
{

private:
	SceneManager();
	~SceneManager();
public:
	SceneManager(const SceneManager& obj) = delete;
	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	void ChangeScene(int sceneNo);

};

