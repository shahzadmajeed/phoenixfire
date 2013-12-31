#ifndef CANNON_H
#define CANNON_H

#include "cocos2d.h"
#include "Weapon.h"

class Cannon : public Weapon
{
// TO BE DONE: let create function input a bullet factory, in order to DIY cannon.
public:
	CREATE_FUNC(Cannon);
	virtual bool init();

	virtual void update(float delta);
};

#endif