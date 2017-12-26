#include "GameObject.h"


GameObject::GameObject()
{
	this->name = "";
	this->listComponent = std::vector<Component*>();
}

GameObject::GameObject(std::string name = "New GameObject")
{
	this->name = name;
	this->listComponent = std::vector<Component*>();
}

GameObject::~GameObject(void)
{
	for(auto it = this->listComponent.begin(); it != this->listComponent.end(); ++it)
	{
		delete (*it);
	}
}

std::string GameObject::GetName()
{
	return this->name;
}

std::vector<Component*> GameObject::GetListComponent()
{
	return this->listComponent;
}