#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "GameObject.h"


class Scene
{
public:
	Scene(void);
	Scene(std::string pathFile);
	~Scene(void);

	std::string GetName();
	std::vector<GameObject*> GetListGameObject();
	GameObject* GetGameObjectByName(std::string name);

private:
	std::string m_name;
	std::vector<GameObject*> listGameObject;
	std::string m_pathFile;

	void LoadDataFromFile();
};

