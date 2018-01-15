#include "GameObject.h"


/*
GameObject::GameObject(QObject* parent) : QObject(parent)
{
	this->name = "";
	this->listComponent = std::vector<Component*>();
	this->xRot = 0;
	this->yRot = 0;
	this->zRot = 0;

	this->selected = false;
}*/

GameObject::GameObject(std::string name = "New GameObject", QObject* parent) : QObject(parent)
{
	this->name = name;
	this->listComponent = std::vector<Component*>();
	this->xRot = 0;
	this->yRot = 0;
	this->zRot = 0;

	this->selected = false;
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