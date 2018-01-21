#include "Component.h"


Component::Component(int id, std::string completeName, Material* material)
{
	this->material = material;
	this->id = id;
	this->completeName = completeName;
	this->worldPosition.x = 0.f;
	this->worldPosition.y = 0.f;
	this->worldPosition.z = 0.f;
	this->isSelected = false;
	scaleX = 1.f, scaleY = 1.f, scaleZ = 1.f;
	translateX = 0.f, translateY =0.f, translateZ =0.f;
	rotateX = 0.f, rotateY = 0.f, rotateZ = 0.f;
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

Component::Point Component::GetPosition()
{
	return this->worldPosition;
}

bool Component::GetIsSelected() const
{
	return this->isSelected;
}

void Component::SetIsSelected(bool b)
{
	this->isSelected = b;
}

void Component::SetPosition(Point pos)
{
	this->worldPosition.x = pos.x;
	this->worldPosition.y = pos.y;
	this->worldPosition.z = pos.z;
}

std::string Component::GetCompleteName()
{
	return this->completeName;
}

void Component::SetType(std::string t)
{
	if (this->completeName == "")
	{
		this->completeName = this->id + " - " + t;
	}

	this->type = t;
}

Component::Point Component::GetPivot()
{
	return this->pivot;
}

void Component::SetPivot(Point p)
{
	this->pivot = p;
}

int Component::GetId()
{
	return this->id;
}