#ifndef TESTBULLET1_H
#define TESTBULLET1_H

#include "cocos2d.h"
#include "Bullet.h"

class TestBullet1 : public Bullet
{
private:
	float speed;

public:
	CREATE_FUNC(TestBullet1);
	virtual bool init();

	virtual void update(float delta);
};

#endif
