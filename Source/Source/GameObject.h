#pragma once

#include <string>
#include <vector>
#include <qevent.h>
#include "Component.h"

class GameObject : public QObject
{
	Q_OBJECT // ATTENTION !!! Si ceci n'existe pas, ca provoque une vieille erreur de linkage par Qt qui ne comprends plus ce qu'est un signal

public:
	struct Point
	{
	public:
		float x;
		float y;
		float z;
	};

	//GameObject(QObject* parent = 0);
	GameObject(std::string name, QObject* parent = 0);
	~GameObject(void);

	void AddComponent(Component* component);
	std::string GetName();
	std::vector<Component*> GetListComponent();
	Point GetPivot();
	void SetPivot(Point p);

	std::string CheckTypeComponent(std::string name);
	void RemoveComponent(Component* component);
	Component* GameObject::GetComponentByName(std::string& name);

public slots:
	void SetXRotation(int angle);
	void SetYRotation(int angle);
	void SetZRotation(int angle);

signals:
	void xRotationChanged(int angle);
	void yRotationChanged(int angle);
	void zRotationChanged(int angle);

protected:
	void NormalizeAngle(int &angle);

private:
	std::string name;
	std::vector<Component*> listComponent;
	int xRot;
	int yRot;
	int zRot;
	Point pivot;
	bool selected;
};

