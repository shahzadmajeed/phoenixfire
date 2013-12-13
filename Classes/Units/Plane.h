#ifndef PLANE_H
#define PLANE_H

#include "cocos2d.h"
#include <vector>
#include "../Weapons/Weapon.h"

class Plane : public cocos2d::CCSprite
{
public:
	enum Status
	{
		ALIVE,
		DEAD,
	};

	bool initWithFile(const char *pszFilename);

	void setStatus(Status status);
	Status getStatus();

	void setLife(float life);
	float getLife();

	void addWeapon(Weapon *weapon);

	void update(float delta);
	virtual void moveTo(cocos2d::CCPoint destination);

private:
	Status status;
	float life;
	std::vector<Weapon*> weapons;
};

#endif