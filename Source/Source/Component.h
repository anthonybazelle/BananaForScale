#pragma once

#include <stddef.h>
#include <string>
#include "Material.h"
#include "Log.h"

class Component
{
public:
	struct Point
	{
		public:
			float x;
			float y;
			float z;
	};

	Component::Component(int id, std::string completeName = "", Material* material = NULL);
	~Component(void);

	Material* GetMaterial();
	std::string GetType();
	void SetType(std::string t);
	Point GetPivot();
	void SetPivot(Point p);
	int GetId();
	Component::Point GetPosition();
	void SetPosition(float x, float y, float z);
	std::string GetCompleteName();
	bool GetIsSelected() const;
	void SetIsSelected(bool b);

	float scaleX, scaleY, scaleZ;
	float translateX, translateY, translateZ;
	float rotateX, rotateY, rotateZ;
	Point worldPosition;

private:
	Material* material;
	std::string type;
	Point pivot;
	int id;
	bool isSelected;
	std::string completeName;
};

