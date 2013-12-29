#ifndef TESTBULLET_H
#define TESTBULLET_H

#include "cocos2d.h"
#include "Bullet.h"

class TestBullet : public Bullet
{
private:
	float speed;
public:
	CREATE_FUNC(TestBullet);
	bool init();

	virtual void update(float delta);
};

#endif