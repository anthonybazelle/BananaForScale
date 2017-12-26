#include "Component.h"


Component::Component(Material* material = NULL)
{
	this->material = material;
}

Component::~Component(void)
{
}

Material* Component::GetMaterial()
{
	return this->material;
}