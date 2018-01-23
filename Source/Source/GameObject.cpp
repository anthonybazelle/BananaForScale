#include "GameObject.h"
//#include "Render.h"


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
	for (auto it = this->listComponent.begin(); it != this->listComponent.end(); ++it)
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
	
	//Render::getInstance()->mutex.lock();
	return this->listComponent;
	//Render::getInstance()->mutex.unlock();
}

void GameObject::AddComponent(Component* component)
{
	this->listComponent.push_back(component);
}

void GameObject::RemoveComponent(Component* component)
{
	for (int i = 0; i < this->listComponent.size(); ++i)
	{
		if (this->listComponent[i] == component)
		{
			this->listComponent.erase(this->listComponent.begin() + i);
			break;
		}
	}
}

Component* GameObject::GetComponentByName(std::string& name)
{
	if (this != NULL)
	{
		for (auto it = this->listComponent.begin(); it != this->listComponent.end(); ++it)
		{
			if ((*it)->GetCompleteName().compare(name) == 0)
			{
				return (*it);
			}
		}
	}
	return NULL;
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