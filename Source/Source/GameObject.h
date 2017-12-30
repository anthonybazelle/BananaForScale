#pragma once

#include <string>
#include <vector>
#include <QGLWidget>
#include "ui_engine.h"
#include <qevent.h>
#include "Render.h"
#include "Component.h"


class GameObject : public QObject
{
	Q_OBJECT // ATTENTION !!! Si ceci n'existe pas, ca provoque une vieille erreur de linkage par Qt qui ne comprends plus ce qu'est un signal

public:
	GameObject(Render* render, QObject* parent = 0);
	GameObject(Render* render, std::string name, QObject* parent = 0);
	~GameObject(void);

	std::string GetName();
	std::vector<Component*> GetListComponent();

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
	QColor qtGreen;
	QColor qtPurple;
	Render* pRender;

	bool selected;
};

