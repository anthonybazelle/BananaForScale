#include "Engine.h"


// Singleton engine cause only one engine running
Engine* Engine::instance = NULL;


Engine::Engine(void)
{
	if(this->instance == NULL)
	{
		this->instance = this;
	}

	this->listScene = std::vector<Scene*>();
}


Engine::~Engine(void)
{
	// delete all Scene
	for(int i = 0; i < this->listScene.size(); ++i)
	{
		delete listScene[i];
	}
}


Engine* Engine::GetInstance()
{
	if(instance == NULL)
	{
		instance = this;
	}

	return instance;
}

int Engine::AddScene(Scene* s)
{
	// Test if Scene with same name already exist
	try
	{
		for(auto it = this->listScene.begin(); it != this->listScene.end(); ++it)
		{
			if(s->GetName().compare((*it)->GetName()) == 0)
			{
				return -1; // If Scene Already exist have the same name as the new one.
			}
		}
	}
	catch(std::exception e)
	{
		std::cout << e.what() << std::endl;
		return -1; // If any other error occur
	}

	this->listScene.push_back(s);
	return 0; // no error
}

int Engine::RemoveScene(Scene* s)
{
	try
	{
		for(auto it = this->listScene.begin(); it != this->listScene.end(); ++it)
		{
			if((*it) == s)
			{
				this->listScene.erase(it); // Erase the scene from running engine
				return 0;
			}
		}
	}
	catch(std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Scene already erased from runinng application or didn't exist." << std::endl;
	return -1;
}

Scene* Engine::RetrieveSceneByName(std::string name)
{
	for(auto it = this->listScene.begin(); it != this->listScene.end(); ++it)
	{
		if((*it)->GetName().compare(name) == 0)
		{
			return (*it);
		}
	}

	return NULL;
}