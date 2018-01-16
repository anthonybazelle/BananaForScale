#pragma once

#include <stddef.h>
#include <string>
#include "Material.h"


class Component
{
public:
	Component(Material* material);
	~Component(void);

	Material* GetMaterial();
	std::string GetType();
	void SetType(std::string t);

private:
	Material* material;	
	std::string type;
};

