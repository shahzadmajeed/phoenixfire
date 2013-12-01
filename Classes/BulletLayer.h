#ifndef _BULLETLAYER_H_
#define _BULLETLAYER_H_

#include "cocos2d.h"
#include "Bullet.h"

class BulletLayer : public cocos2d::CCLayer
{
private:
	cocos2d::CCSpriteBatchNode *bulletBatchNode;

public:
	static BulletLayer* create();
	virtual bool init();
	void addBullet(Bullet::BulletType type, cocos2d::CCPoint position);

	static BulletLayer *sharedBulletLayer;
};

#endif