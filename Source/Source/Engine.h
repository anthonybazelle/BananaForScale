#pragma once

#include <stddef.h>
#include <vector>
#include <exception>
#include <iostream>

#include "Scene.h"

class Engine
{
public:
	Engine(void);
	~Engine(void);

	Engine* GetInstance();

private:
	static Engine* instance;
	std::vector<Scene*> listScene; // Multiple Scene Management

	int AddScene(Scene* s);
	int RemoveScene(Scene* s);
	Scene* RetrieveSceneByName(std::string name);
};

