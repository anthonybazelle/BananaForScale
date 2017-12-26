#pragma once

#include <string>
#include <vector>

#include "Component.h"


class GameObject
{
public:
	GameObject();
	GameObject(std::string name);
	~GameObject(void);

	std::string GetName();
	std::vector<Component*> GetListComponent();

private:
	std::string name;
	std::vector<Component*> listComponent;
};

