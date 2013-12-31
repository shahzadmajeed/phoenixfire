#ifndef PLANEFACTORY_H
#define PLANEFACTORY_H

#include "cocos2d.h"
#include "Plane.h"

class PlaneFactory
{
public:
	static enum PlaneType
	{
		HERO1,
		ENEMY1,
	};

	Plane* createPlane(PlaneType type);
};

#endif