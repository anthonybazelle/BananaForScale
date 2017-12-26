#pragma once

#include <stddef.h>

#include "Material.h"


class Component
{
public:
	Component(Material* material);
	~Component(void);

	Material* GetMaterial();

private:
	Material* material;	
};

