#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include "GameObject.h"


class Scene
{
public:
	Scene(void);
	Scene(std::string pathFile);
	~Scene(void);

	std::string GetName();
	void SetName(std::string name);
	std::vector<GameObject*> GetListGameObject();
	GameObject* GetGameObjectByName(std::string& name);
	void AddGameObject(GameObject* go);
	std::string CheckName(std::string name);

private:
	std::string m_name;
	std::vector<GameObject*> listGameObject;
	std::string m_pathFile;

	void LoadDataFromFile();
};

