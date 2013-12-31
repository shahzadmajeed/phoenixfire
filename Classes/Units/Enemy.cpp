#include "Enemy.h"

USING_NS_CC;

bool Enemy::init(const char *name)
{
	if (!Plane::init(name)) return false;

	srand((unsigned int)(time(NULL)));
	move();

	return true;
}


void Enemy::move()
{
	CCAction *moveAction = CCSequence::create(
		CCMoveTo::create(5, ccp((rand()%760), (rand()%(1280-800))+800)),
		CCCallFunc::create(this, callfunc_selector(Enemy::move)),
		NULL);
	runAction(moveAction);
}