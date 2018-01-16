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

std::string Component::GetType()
{
	return this->type;
}

void Component::SetType(std::string t)
{
	this->type = t;
}