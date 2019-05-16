#pragma once

#include "Shape.h"
#include <vector>

class ShapeList: public Shape
{
public:
	std::vector<Shape*> list;

	ShapeList()
	{
		list = std::vector<Shape*>();
	};


	virtual bool hit(const Ray& ray, float tMin, float tMax, hitRecord& hit) const
	{
		hitRecord tempHit;
		bool hitAnything = false;
		double closestSoFar = tMax;

		for(const Shape *shape: this->list)
		{
			if (shape->hit(ray, tMin, closestSoFar, tempHit))
			{
				hitAnything = true;
				closestSoFar = tempHit.t;
				hit = tempHit;
			}
		}

		return hitAnything;
	}

	void append(Shape *shape)
	{
		list.push_back(shape);
	}
};

