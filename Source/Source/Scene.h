#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "GameObject.h"


class Scene
{
public:
	Scene(void);
	~Scene(void);

	std::string GetName();
	std::vector<GameObject*> GetListGameObject();
	GameObject* GetGameObjectByName(std::string name);

private:
	std::string name;
	std::vector<GameObject*> listGameObject;
};

