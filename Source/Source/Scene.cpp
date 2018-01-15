#include "Scene.h"


Scene::Scene(void)
{
	this->listGameObject = std::vector<GameObject*>();
	this->m_name = "";
}

Scene::Scene(std::string pathFile)
{
	this->m_pathFile = pathFile;
	LoadDataFromFile();
}


Scene::~Scene(void)
{

}

std::string Scene::GetName()
{
	return this->m_name;
}

std::vector<GameObject*> Scene::GetListGameObject()
{
	return this->listGameObject;
}

GameObject* Scene::GetGameObjectByName(std::string name)
{
	try
	{
		for(auto it = this->listGameObject.begin(); it != this->listGameObject.end(); ++it)
		{
			if((*it)->GetName().compare(name) == 0)
			{
				return (*it);
			}
		}
	}
	catch(std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	return NULL;
}

void Scene::LoadDataFromFile()
{
	// TODO : Charger tous les GameObject provenant du fichier, ainsi que le nom de la scene
	// juste pour les tests :
	if (m_pathFile.find("1") != std::string::npos)
	{
		this->m_name = "Tab 1";
	}
	else if (m_pathFile.find("2") != std::string::npos)
	{
		this->m_name = "Tab 2";
	}
}