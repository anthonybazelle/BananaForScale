#include "Scene.h"


Scene::Scene(void)
{
	this->listGameObject = std::vector<GameObject*>();
}

Scene::~Scene(void)
{

}

std::string Scene::GetName()
{
	return this->name;
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