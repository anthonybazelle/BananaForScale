#include "GameObject.h"



GameObject::GameObject(std::string name = "New GameObject", QObject* parent) : QObject(parent)
{
	this->name = name;
	this->listComponent = std::vector<Component*>();
	this->xRot = 0;
	this->yRot = 0;
	this->zRot = 0;

	this->pivot.x = 0.f;
	this->pivot.y = 0.f;
	this->pivot.z = 0.f;

	this->selected = false;
}



/*
GameObject::GameObject(QObject* parent) : QObject(parent)
{
	this->name = "";
	this->listComponent = std::vector<Component*>();
	this->xRot = 0;
	this->yRot = 0;
	this->zRot = 0;

	this->selected = false;
}
*/

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

std::string GameObject::CheckTypeComponent(std::string type)
{
	bool isChecked = false;
	int countSame = 1;

	while (!isChecked)
	{
		for (auto it = this->listComponent.begin(); it != this->listComponent.end(); ++it)
		{
			if ((*it)->GetType().compare(type) == 0)
			{
				break;
			}
		}
		type = type + " (" + std::to_string(countSame) + ")";
		++countSame;
	}

	return type;
}

std::vector<Component*> GameObject::GetListComponent()
{
	return this->listComponent;
}

void GameObject::AddComponent(Component* component)
{
	this->listComponent.push_back(component);
}

void GameObject::SetXRotation(int angle)
{
	NormalizeAngle(angle);
	if (angle != this->xRot)
	{
		this->xRot = angle;
		emit xRotationChanged(angle); // emit permet d'envoyer un signal à la fenetre Qt
		//this->pRender->updateGL(); // fonction Qt permettant d'appeler glDraw()
	}
}

GameObject::Point GameObject::GetPivot()
{
	return this->pivot;
}

void GameObject::SetPivot(GameObject::Point p)
{
	this->pivot = p;
}

void GameObject::SetYRotation(int angle)
{
	NormalizeAngle(angle);
	if (angle != this->yRot)
	{
		this->yRot = angle;
		emit yRotationChanged(angle); // emit permet d'envoyer un signal à la fenetre Qt
		//this->pRender->updateGL(); // fonction Qt permettant d'appeler glDraw()
	}
}

void GameObject::SetZRotation(int angle)
{
	NormalizeAngle(angle);
	if (angle != this->zRot)
	{
		this->zRot = angle;
		emit zRotationChanged(angle); // emit permet d'envoyer un signal à la fenetre Qt
		//this->pRender->updateGL(); // fonction Qt permettant d'appeler glDraw()
	}
}

void GameObject::NormalizeAngle(int &angle)
{
	while (angle < 0)
		angle += 360 * 16;
	while (angle > 360)
		angle -= 360 * 16;
}